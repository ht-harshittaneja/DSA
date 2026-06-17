/* 
Painter's Partition
You are given A painters and an array C of N integers where C[i] denotes the length of the ith board. 
Each painter takes B units of time to paint 1 unit of board. You must assign boards to painters such that:

* Each painter paints only contiguous segments of boards.
* No board can be split between painters.
* The goal is to minimize the time to paint all boards.

Return the minimum time required to paint all boards modulo 10000003.
*/

/* 
Optimal Approach : O(nlog(sum-max+1))
Search on maximum board length assigned to a painter.
Range: largest board → sum of all boards.
Assume a maximum workload X.
Greedily assign contiguous boards and count painters needed.
If painters needed ≤ A, X is valid → try smaller.
Else, X is too small → try larger.
*/
class Solution {
public:
    int paint(int A, int B, vector<int>& C) {
       /* if(A > C.size()) return -1; */
        int lo =INT_MIN ;
        int hi =0 ;
        for(int x: C){
            hi+=x;
            lo = max(lo,x);
        }
        int maxlen=-1 ;
        while(lo<=hi){
            int mid = lo +(hi-lo)/2;
            int subArrays = noOfSubArrays(C,mid);
            if(subArrays <= A){
                maxlen= mid;
                hi=mid-1;
            }
            else lo = mid + 1;
        }
        int time = (maxlen*B)%10000003;
        return time;
    }
    int noOfSubArrays(vector<int> &C, int mid){
        int subArrays = 1;
        int count =0 ;
        for(int x : C){
            if(count + x > mid){
                count = 0;
                subArrays++;
            }
            count +=x;
        }
        return subArrays;
    }
};