/*
Recursive Bubble Sort
Given an array of integers nums, sort the array in non-decreasing order using the recursive Bubble Sort algorithm, and return the sorted array.

You must implement Bubble Sort using recursion only.
Do not use built-in sorting functions (sort, sorted, Arrays.sort, etc.).
A sorted array in non-decreasing order is an array where each element is greater than or equal to the previous one.
*/

/*
Optimal Approach : TC-O(N^2) SC-O(N)
max always holds the previous index
At each step, if nums[prev] > nums[j] → swap, so the larger one moves forward
By end of loop, largest element is guaranteed at the last position
Then recurse on n-1 elements
*/

class Solution {
public:
    vector<int> bubbleSort(vector<int>& nums) {
        if(nums.size()<=1) return nums ;// if empty 
        // necessary condition
         int max=0;
         for(int j=1; j<nums.size() ;j++){
            if(nums[max]>nums[j]){
                    swap(nums[j],nums[max]);
                }
                max=j;  // common in if / else statement so no need of else
        }
        int last = nums.back();
        nums.pop_back();
        bubbleSort(nums);
        nums.push_back(last);

        return nums;
    }
};
