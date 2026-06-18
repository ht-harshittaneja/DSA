/* 
Find row with maximum 1's
Given a non-empty grid mat consisting of only 0s and 1s, where all the rows are sorted in ascending order, 
find the index of the row with the maximum number of ones.
If two rows have the same number of ones, consider the one with a smaller index. If no 1 exists in the matrix, return -1.
*/

/* 
Optimal Approach : O(m log n)
Find the first occurrence of 1 in a row using binary search.
Number of 1s in that row:
count = m - firstOneIndex
Keep track of the row having the maximum count.
*/

class Solution {
  public:   
  int rowWithMax1s(vector < vector < int >> & mat) {
    int m = mat.size();
    int ans = -1;
    int count = 0 ;

    for(int i=0 ; i<m ;i++){
        int temp = lowerBound(mat[i]);

        if(temp>count){
            count =temp;
            ans= i;
        }
    }
    return ans ;
  }
  int lowerBound(vector<int>& v){
    int n = v.size();
    int lo = 0;
    int hi = n-1;
    int count = 0 ;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2 ;

        if(v[mid]==1){
            count = n-mid;
            hi = mid-1;
        }
        else lo =mid+1; 
    }
    return count;
  }
};