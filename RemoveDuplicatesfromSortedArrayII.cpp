/*
 Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3]. 

// The following code can be mordified to allow any number of duplicates 
(just change the value of 'kmax' to the corresponding number)

*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int j=0,i=0;
        int kmax = 2;
        while(i<n)
        {
            int k=1;
            A[j++] = A[i++];
            while(A[i]==A[i-1]&&k<kmax&&i<n)
            {
                A[j++] = A[i++];
                k++;
            }
            if(i<n)
            {
               while(A[i]==A[i-1]) 
                  i++;
            }
        }
        return j;
    }
};
