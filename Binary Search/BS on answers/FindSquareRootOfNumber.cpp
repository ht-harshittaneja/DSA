/* 
Find square root of a number
Given a positive integer n. Find and return its square root. If n is not a perfect square, then return the floor value of sqrt(n).
*/

/* 
Optimal Approach : O(log(n))
Search range: 1 to n.
Pick a middle number and square it.
If square ≤ n: it is a possible answer → store it and try a larger number.
If square > n: number is too large → try a smaller number.
Continue until search ends.
Return the largest number whose square is ≤ n.
*/

class Solution {
public:
    int floorSqrt(int n)  {
        if(n == 0) return 0;
        int lo =1;
        int hi =n;
        int ans=1;

        while(lo<=hi){
            int mid = lo+ (hi-lo)/2;
            long long val =  1LL*mid*mid;
            if(val <= n){
                ans= mid;
                lo= mid+1; 
            }
            else hi = mid-1 ;
        }
        return ans; 
    }
};