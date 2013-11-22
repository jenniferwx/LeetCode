/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it 
without using extra memory?

*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int d;
        for(int i=1;i<n;i++)
        {
            A[i] = A[i-1]^A[i];
        }
        return A[n-1];
    }
};
