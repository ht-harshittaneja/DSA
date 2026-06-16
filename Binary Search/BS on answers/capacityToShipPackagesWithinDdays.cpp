/* 
leetcode 1011. Capacity To Ship Packages Within D Days
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
 */

/* 
Optimal Approach: O(n*log(sum-max+1))     O(n*log(sum))
Minimum capacity = largest package.
Maximum capacity = sum of all packages.
Pick a capacity.
Compute how many days are needed.
If days needed ≤ target days → capacity works, try smaller.
Otherwise → capacity too small, try larger.
*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
    int lo = weights[0];
    int hi = 0 ;
    for (int x : weights) {
    lo = max(lo, x);
    hi += x;
    }
    int ans = -1 ;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        int totalDays = noOfDays(weights,mid);
        if(totalDays <= days){
            ans = mid;
            hi = mid -1 ;
        }
        else lo =mid +1 ;
    }
    return ans;         
    }

    int noOfDays(vector<int>& weights , int mid){
    int totalDays = 1 ;
    int sum =0 ;
    for(int x : weights){
        if(sum + x >mid){
            totalDays++;
            sum =0;
        }
        sum +=x;
    }   
    return totalDays;
    }
};