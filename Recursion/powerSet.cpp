/*
Power Set
Given an array of integers nums of unique elements. Return all possible subsets (power set) of the array.
Do not include the duplicates in the answer.
*/

/*
Optimal Approach : O(2^n)
Start with an empty subset (ans) and the given array (nums).
At each recursive call, consider the last element of the remaining array.
Exclude the current element and recursively generate all subsets without it.
Include the current element in the current subset (ans) and recursively generate all subsets.
When no elements are left (nums.empty()), store the current subset in the answer.
Since every element has two choices (include or exclude), all possible subsets are generated, resulting in the complete power set.
*/

class Solution {
public:	
    vector<vector<int> > powerSet(vector<int>& nums) {
        //your code goes here
        vector<vector<int>> answer ; 
        vector<int>ans;
        helper(answer,ans,nums);
        return answer;
    }
    void helper(vector<vector<int>>& answer,vector<int> ans ,vector<int> nums ){
        if(nums.empty()){
            answer.push_back(ans);
            return;
        }
        int end= nums.back();
        nums.pop_back();
        helper(answer,ans ,nums);
        ans.push_back(end);
        helper(answer,ans ,nums);
    }
};