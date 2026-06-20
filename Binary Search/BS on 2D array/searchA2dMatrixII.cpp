/*
leetcode - 240. Search a 2D Matrix II
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/

/*
Optimal Approach : O()
top-right works
At matrix[row][col]:
    Everything to the left in that row is smaller.
    Everything below in that column is larger.

So when you compare matrix[row][col] to target:
If matrix[row][col] < target → the target can't be anywhere in this row (everything left is even smaller). 
So safely discard the entire row → row++.

If matrix[row][col] > target → the target can't be anywhere in this column (everything below is even bigger). 
So safely discard the entire column → col--.
*/

class Solution{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target){
        int m =matrix.size();
        if(m==0) return false;
        int n =matrix[0].size();
        int row = 0;
        int col = n-1;

        while(row<m && col >=0){
            if(matrix[row][col] == target) return true ;
            else if(matrix[row][col] < target) row ++;
            else col-- ;
        }
        return false ;
    }
};