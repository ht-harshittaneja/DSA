/* 
leet code 4. Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
*/

/*  
Optimal Approach : O(log(min(n1,n2)))
Apply binary search on the smaller array
If n1 > n2, swap the arrays.
Choose a partition in Array 1
cut1 = (lo + hi) / 2
Find corresponding partition in Array 2
cut2 = (n1 + n2 + 1)/2 - cut1
Ensures left half contains half the total elements.
Find partition boundary elements
l1 = nums1[cut1-1], r1 = nums1[cut1]
l2 = nums2[cut2-1], r2 = nums2[cut2]
Use INT_MIN and INT_MAX when partition touches array boundaries.
Check if partition is valid
l1 <= r2
l2 <= r1
If true, all left-half elements are ≤ all right-half elements.
Calculate median
Even length: (max(l1,l2) + min(r1,r2)) / 2
Odd length: max(l1,l2)
Adjust binary search
If l1 > r2, move left (hi = cut1 - 1)
Else move right (lo = cut1 + 1)
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n2<n1) return findMedianSortedArrays(nums2,nums1);
        int lo =0 ;
        int hi = n1;
        
        while(lo<=hi){
        int cut1= lo + (hi-lo)/2;
        int cut2 = (n1+n2+1)/2 - cut1;

        int l1 = cut1==0 ? INT_MIN : nums1[cut1-1];
        int l2 = cut2==0 ? INT_MIN : nums2[cut2-1];

        int r1 = cut1==n1 ? INT_MAX : nums1[cut1];
        int r2 = cut2==n2 ? INT_MAX : nums2[cut2];

        if(l1<=r2 && l2<=r1){
            if((n1+n2)%2 ==0) 
            return (double(max(l1,l2))+min(r1,r2))/2.0 ;

            else return max(l1,l2);
        }
        else if(l1>r2) hi = cut1 -1 ;
        else lo = cut1 +1 ;
        }
        return 0.0;
    }
};