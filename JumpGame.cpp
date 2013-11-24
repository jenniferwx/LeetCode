/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false. 

*/
class Solution {
public:
    // Solution 1:
    bool canJump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n<=0)
        return false;

        int maxDist = 0,i,j;
        for(i=0;i<n;i++)
        {
            j = i;
            while(j<n)
            {
                if(A[j]==0 && maxDist<n-1)
                return false;
                
                maxDist = A[j] + j;
                if(maxDist>=n-1)
                return true;
                
                j = maxDist;
            }
        }
        return false;
    }
    
    // Better and simple solution:
        bool canJump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n<=0)
        return false;

        int maxDist = 0, start = 0, end = 0;
        while(start<=end && end<n)
        {
            end = max(end, A[start] + start);
            start++;
        }
        return end>=n-1;
    }
};
};
