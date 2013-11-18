/*
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.
More practice:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, 
which is more subtle.

Written by Xi Wang
11/17/2013
*/

class Solution {
public:
 // SOUTION 1: Divide and COnquer O(NLogN)
    int maxCrossArray(int A[],int l,int mid,int r)
    {
        if(l>r)
        return 0;
        int left_sum = INT_MIN, sum=0;
        for(int i=mid;i>=l;i--)
        {
            sum +=A[i];
            if(sum > left_sum)
            left_sum = sum;
        }
        
        int right_sum = INT_MIN;
        sum=0;
        for(int i=mid+1;i<=r;i++)
        {
            sum +=A[i];
            if(sum > right_sum)
            right_sum = sum;
        }
        
        return left_sum+right_sum;
        
    }
    int maxSubArray(int A[],int l, int r)
    {
        if(l==r)
        return A[l];
        int mid = (l+r)/2;
        int leftmax = maxSubArray(A,l,mid);
        int rightmax = maxSubArray(A,mid+1,r);
        int crossmax = maxCrossArray(A,l,mid,r);
        return max(max(leftmax,rightmax),crossmax);
    }
    int maxSubArray(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return maxSubArray(A,0,n-1);
    }
    
    // solution 2: linear approach O(n)
    int maxSubArray(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int sum = 0, max = INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum +=A[i];
            if(sum>max)
            max = sum;
            if(sum<=0)
            sum=0;
        }
        return max;
        
    }
};
