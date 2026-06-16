/* 
Aggressive Cows
Given an array nums of size n, which denotes the positions of stalls, and an integer k,
which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance 
between any two cows is the maximum possible. Find the maximum possible minimum distance.
*/

/* 
Optimal Approach : O(nlogn + nlog(max-min))
Sort the stall positions.
Binary search on the minimum distance between cows.
For a given distance d, greedily place cows in the leftmost possible stalls while maintaining at least d distance.
If at least k cows can be placed, d is feasible; try a larger distance.
Otherwise, reduce the distance.
The largest feasible distance is the answer.
*/

class Solution {
public:
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int lo = nums[1]-nums[0];
        for(int i =0 ; i<nums.size()-1 ; i++){
            lo= min(lo,nums[i+1]-nums[i]);
        }
        int hi = nums[nums.size()-1]-nums[0];

        int ans = 0;
        while(lo<=hi){
            int mid= lo + (hi - lo)/2;
            int cows = noOfCows(nums,mid);

            if(cows>=k){
                ans = mid ;
                lo =mid +1 ;
            }
            else hi = mid -1 ;
        }
        return ans;
    }

    int noOfCows(vector<int> &nums , int mid){
        int count = 1;
        int last =nums[0];
        for(int i =0 ; i<nums.size() ; i++){
            int diff = nums[i] - last ;

            if(diff >= mid){
                count++;
                last= nums[i];
            }
        }
        return count ;
    }
};