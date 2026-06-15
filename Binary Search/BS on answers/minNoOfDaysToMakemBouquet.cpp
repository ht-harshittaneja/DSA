/* 
leetcode 1482.Minimum Number of Days to Make m Bouquets

You are given an integer array bloomDay, an integer m and an integer k.
You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
*/

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
    int lo = INT_MAX;
    int hi = INT_MIN ;
    for (int x : bloomDay) {
    lo = min(lo, x);
    hi = max(hi, x);
    }
    int ans = -1 ;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        int totalBouquet = noOfBouquet(bloomDay,mid,k);
        if(totalBouquet >= m){
            ans = mid;
            hi = mid -1 ;
        }
        else lo =mid +1 ;
    }
    return ans;         
    }
    int noOfBouquet(vector<int>& bloomDay , int mid ,int k){
    int totalBouquet =0 ;
    int count =0 ;
    for(int x : bloomDay){
        if(x <=mid) count ++;
        else count =0 ;

        if(count == k){
            totalBouquet++;
            count =0;
        }
    }
    return totalBouquet;
    }
};