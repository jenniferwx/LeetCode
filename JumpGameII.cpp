/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to 
the last index.)

*/

class Solution {
public:
    int jump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n<=0)
        return 0;
        
        int start = 0;
        int step = 0;
        while(start<n-1)
        {
            step ++;
            int end = A[start] + start;
            if(end>=n-1)
            return step;
            
            int nextstart = start;
            for(int i=start+1;i<=end;i++)
            {
                if((A[i]+i) >= (A[nextstart]+ nextstart))  // pay attention to this line
                nextstart = i;
            }
            start = nextstart;
        }
        return step;
    }
};
