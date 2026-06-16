/* 
Book Allocation Problem
Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book, 
and an integer m representing the number of students, allocate all the books to the students so 
that each student gets at least one book, each book is allocated to only one student, and the allocation is contiguous.
Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized. 
If the allocation of books is not possible, return -1.
*/

/*  
Optimal Approach : O(n*log(sum-max+1))
Search on maximum pages per student.
Range: max(book) → sum(all books).
For a page limit X, allocate books greedily.
Count students needed.
If students needed ≤ m, try a smaller X.
Else, try a larger X.
*/

class Solution {
public:
    int findPages(vector<int> &nums, int m) {
    if(nums.size()<m) return -1;
    int lo = INT_MIN ;
    int hi = 0;
    for(int x: nums){
        hi+=x;
        lo=max(lo,x);
    }
    int ans = -1 ;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        int students = noOfStudents(nums,mid);
        if(students <= m){
            ans = mid;
            hi = mid -1 ;
        }
        else lo =mid +1 ;
    }
    return ans;
    }
    int noOfStudents(vector<int> &nums,int mid){
        int students = 1 ;
        int pages =0 ;
        for(int x : nums){
            if(pages + x >mid){
                students ++ ;
                pages =0;
            }
            pages +=x;
        }
        return students ;
    }
};