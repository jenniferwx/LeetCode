/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. The number of elements 
initialized in A and B are m and n respectively.
*/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = m+n-1;
        int i,j;
        for(i=m-1,j=n-1;i>=0&&j>=0;len--)
        {
            if(A[i]>B[j])
            A[len] = A[i--];
            else
            A[len] = B[j--];
        }
        while(i>=0)
            A[len--] = A[i--];
        while(j>=0)
            A[len--] = B[j--];
    }
};
