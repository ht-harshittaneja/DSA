/* 
leet code 162. Find Peak Element
A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time. 
*/

/*
 Optimal Approach:
If you're on an increasing slope (arr[mid] > arr[mid-1]), then a peak must exist on the right side
If you're on a decreasing slope (arr[mid] < arr[mid-1]), then a peak must exist on the left side. 
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int n = nums.size();
      if(n==1) return 0;
      if(nums[0]>nums[1]) return 0 ;
      if(nums[n-1]>nums[n-2]) return n-1 ;
      int lo = 1;
      int hi = n-2;

      while(lo<=hi){
        int mid = lo +(hi-lo)/2;
        if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]) 
            return mid;

        else if (nums[mid-1]<nums[mid]) lo=mid+1;
        else hi = mid-1;
      }
      return -1;    
    }
};
