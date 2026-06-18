/* 
Kth element of 2 sorted arrays
Given two sorted arrays arr1 and arr2 of size m and n respectively, 
return the median of the two sorted arrays.
The median is defined as the middle value of a sorted list of numbers. 
In case the length of the list is even, the median is the average of the two middle elements.
*/

/*  
Optimal Approach : O(log(min(n1,n2)))
Binary search on the smaller array.
Create partitions such that left side contains exactly k elements.
Find the four boundary elements (l1, l2, r1, r2).
Check if partition is valid:
l1 ≤ r2
l2 ≤ r1
If valid, k-th element = largest element on the left side.
Otherwise move partition left or right and repeat.
*/

class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        if(b.size() < a.size()) return kthElement(b, a ,k);

        int n1 = a.size();
        int n2 = b.size();

        int lo = max(0,k-n2);
        int hi = min(k, n1);

        while(lo <= hi) {
            int cut1 = lo + (hi - lo) / 2;
            int cut2 = k - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];

            int r1 = (cut1 == n1) ? INT_MAX : a[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : b[cut2];

            if(l1 <= r2 && l2 <= r1) {
                return max(l1,l2);
            }
            else if(l1 > r2) {
                hi = cut1 - 1;
            }
            else {
                lo = cut1 + 1;
            }
        }
        return -1 ;
    }
};
