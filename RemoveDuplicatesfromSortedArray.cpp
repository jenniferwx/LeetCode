/*
 Given a sorted array, remove the duplicates in place such that each element appear only 
 once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2]. 

*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = n;
        int prev = A[0], k = 1;
        for(int i=1;i<n;i++)
        {
            if(A[i]==prev)
                len --; 
            else
            {
                A[k++] = A[i];
                prev = A[i];
            }
        }
        return len;
        
    }
};
