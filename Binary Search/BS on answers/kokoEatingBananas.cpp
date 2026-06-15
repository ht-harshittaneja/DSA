/* 
leetcode 875. Koko Eating Bananas
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.
*/

/* 
Optimal Approach: O(n*log(max))
Answer range: speed from 1 to max pile.
Pick a speed and calculate total hours needed.
If hours ≤ h: speed works → try smaller speed.
If hours > h: speed too slow → try larger speed.
Repeat until search ends.
Return the smallest working speed.
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    int lo = 1;
    int hi = *max_element(piles.begin(),piles.end());
    int ans = 0 ;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        int temp = 0 ;
        for(int x : piles){
            temp += (x+mid-1)/mid;
            if(temp>h) break;
        }
        if(temp <= h){
            ans = mid;
            hi = mid -1 ;
        }
        else lo =mid +1 ;
    }
    return ans; 
    }
};