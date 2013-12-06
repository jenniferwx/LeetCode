/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).

*/
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
      //  return findMedian_1(A,m,B,n);
        return findMedian_2(A,m,B,n);
    }
    // SOLUTION 1: O(m+n)
    double findMedian_1(int A[], int m, int B[], int n)
    {
        int i=0, j=0;
        int a=0, b=0;
        int total = (m+n);
        for(int k=0;k<=total/2;k++)
        {
            int x = (i==m)?INT_MAX:A[i];
            int y = (j==n)?INT_MAX:B[j];
            
            a = b;
            b = min(x,y);
            if(x<y)
            i++;
            else
            j++;
        }
        if(total & 0x1) return b;
        return (a + b)/2.0;
    }
    
     //SOLUTION 2: O(log(m+n))
    double findMedian_2(int A[], int m, int B[], int n)
    {
        int total = m+n;
        if(total & 0x1 ==1)
        return findKthSortedArrays(A,m,B,n,total/2+1);
        else
        return 0.5*(findKthSortedArrays(A,m,B,n,total/2) + findKthSortedArrays(A,m,B,n,total/2+1));
    }
    double findKthSortedArrays(int A[], int m, int B[], int n, int k)
    {
        if (m > n)
            return findKthSortedArrays(B, n, A, m, k);
        if (m == 0) return B[k-1];
        if (k == 1) return min(A[0], B[0]);

        int i = min(k / 2, m);
        int j = k - i;
        int a = A[i-1];
        int b = B[j-1];

        if (a < b) return findKthSortedArrays(A + i, m - i, B, n, k - i);
        else if (a > b) return findKthSortedArrays(A, m, B + j, n - j, k - j);
        else return a;
    }
};
