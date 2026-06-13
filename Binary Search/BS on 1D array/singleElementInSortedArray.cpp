/* 
leetcode 540. Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space. 
*/

//Brute force Approach 
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) return arr[0];

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (arr[i] != arr[i + 1])
                    return arr[i];
            }
            else if (i == n - 1) {
                if (arr[i] != arr[i - 1])
                    return arr[i];
            }
            else {
                if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                    return arr[i];
            }
        }
        return -1;
    }
}; 

//Brute force Approach 2 using Xor
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = ans ^ arr[i];
        }
        return ans;
    }
};

// optimal approach
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int hi = nums.size()-2;
        int lo = 1;
        int ans;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1])
            return nums[mid];

            if(mid%2==1){
                if(nums[mid-1]==nums[mid]) lo=mid+1;
                else hi= mid-1;
            }
            else{
                if(nums[mid-1]==nums[mid]) hi= mid-1;
                else lo= mid+1;
            }
        }
        return -1;  
    }
};
