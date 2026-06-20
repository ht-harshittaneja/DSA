/*
leetcode - 74. Search a 2D Matrix
You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.
*/

/*
Optimal Approach : O(log m*n)
Treat the m x n matrix as a single sorted array of size m*n. Binary search over indices 0 to m*n-1, 
converting each flat index mid back to 2D coordinates:
row = mid / n
col = mid % n
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0) return false;
        int n = matrix[0].size();
        
        int lo =0;
        int hi = m*n -1 ;
        while(lo<=hi){
        int mid= lo + (hi-lo)/2;
        if(matrix[mid/n][mid%n]==target) return true;

        if(matrix[mid/n][mid%n] < target) lo =mid+1;
        else hi= mid-1 ;
     }
     return false ;
    }
};