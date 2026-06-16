/* 
Leetcode : 1283. Find the Smallest Divisor Given a Threshold
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.
*/

/* 
Optimal Approach: O(n*log(max))
same as Koko Eating Bananas
Answer range: divisor from 1 to max element.
Pick a divisor and compute the sum of all ceil(num / divisor).
Check validity:
If sum ≤ limit → divisor works.
If sum > limit → divisor is too small.
If divisor works: save it and try a smaller divisor.
If divisor doesn't work: try a larger divisor.
Return the smallest divisor that satisfies the limit.
*/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
    int lo = 1 ;
    int hi = *max_element(nums.begin(),nums.end());
    int ans = -1 ;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        int totalSum = 0;
        for(int x : nums){
            totalSum += (x+mid-1)/mid;
            if(totalSum>threshold) break;
        }

        if(totalSum <= threshold){
            ans = mid;
            hi = mid -1 ;
        }
        else lo =mid +1 ;
    }
    return ans;       
    }
};