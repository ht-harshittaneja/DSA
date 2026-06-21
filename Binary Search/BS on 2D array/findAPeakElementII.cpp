/*
leetcode - 1901. Find a Peak Element II
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
*/

/*
Optimal Approach : O(mlogn)
Binary search on columns.
Pick the maximum element in the middle column.
Compare it with left and right neighbours.
If greater than both, it is a peak.
Otherwise move towards the larger neighbour.

Key Idea:
Choose the largest element of a column. If it is not a peak, 
a peak must exist in the direction of the larger horizontal neighbour. 
Hence binary search on columns.
*/

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        if(m == 0) return {-1,-1};
        int n= mat[0].size();
        int lo = 0;
        int hi = n-1;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int row = largest(mat,mid);
            
            int left = mid > 0 ? mat[row][mid-1] : -1 ;
            int right= mid < n-1 ? mat[row][mid+1] : -1 ;

            if(mat[row][mid]>left && mat[row][mid] > right) return {row,mid};
            else if (mat[row][mid] < right) lo= mid+1;
            else hi= mid-1;
        }
        return {-1,-1};
    }
    int largest(vector<vector<int>>& mat,int mid){
        int idx =0 ;
        for(int i = 1 ; i<mat.size(); i++){
            if(mat[idx][mid]<mat[i][mid]) idx = i;
        }
        return idx ;
    }
};