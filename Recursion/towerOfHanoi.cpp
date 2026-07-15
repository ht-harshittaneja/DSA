/*
You are given n disks placed on a starting rod (from), with the smallest disk on top and the largest at the bottom. 
There are three rods: the starting rod(from), the target rod (to), and an auxiliary rod (aux).
You have to calculate the minimum number of moves required to transfer all n disks from the starting rod to the target rod, 
following these rules:
      1. Only one disk can be moved at a time.
      2. A disk can only be placed on top of a larger disk or on an empty rod.
Return the minimum number of moves needed to complete the task.
*/

/*
Optimal Approach : O(2^n)
If there is only one disk, move it directly (1 move).
Move the top n-1 disks from source to auxiliary.
Move the largest disk from source to destination.
Move the n-1 disks from auxiliary to destination.
Total moves = soure to aux + 1 + aux to desti.
The minimum moves required are 2^n - 1.
*/

class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        if(n==1) return 1;
        
        return towerOfHanoi(n - 1, from, aux, to) + towerOfHanoi(n - 1, aux , to , from) + 1;
    }
};