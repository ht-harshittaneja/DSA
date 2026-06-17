/* 
leetcode 410. Split Array Largest Sum
Given an integer array nums and an integer k, 
split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.
*/

/* 
Optimal Approach : O(nlog(sum-max+1))
Search on largest subarray sum.
Range: max element → sum of all elements.
Assume a maximum allowed subarray sum X.
Greedily form subarrays and count how many are needed.
If subarrays needed ≤ k, X is valid → try smaller.
Else, X is too small → try larger.
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()) return -1;
        int lo =INT_MIN ;
        int hi =0 ;
        for(int x: nums){
            hi+=x;
            lo = max(lo,x);
        }
        int ans=-1 ;
        while(lo<=hi){
            int mid = lo +(hi-lo)/2;
            int subArrays = noOfSubArrays(nums,mid);
            if(subArrays <= k){
                ans= mid;
                hi=mid-1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
    int noOfSubArrays(vector<int> &nums, int mid){
        int subArrays = 1;
        int count =0 ;
        for(int x : nums){
            if(count + x > mid){
                count = 0;
                subArrays++;
            }
            count +=x;
        }
        return subArrays;    
    }
};