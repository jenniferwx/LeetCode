/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n==1&&A[0]==target)
        return vector<int>(2,0);
        vector<int> result(2,-1);
        BinarySearch(A,0,n-1,target,result);
        return result;
    }
    void BinarySearch(int A[],int left,int right,int target,vector<int> &result)
    {
        if(left>right)
        return;
        int mid = (left+right)/2;
        
        if(A[mid]==target)
        {
            result[0] = result[0]==-1?mid:min(result[0],mid);
            result[1] = result[1]==-1?mid:max(result[1],mid);
        }
        if(A[mid-1]==target || A[mid]>target)
            BinarySearch(A,left,mid-1,target,result);
        if(A[mid+1]==target || A[mid]<target)
            BinarySearch(A,mid+1,right,target,result);
    }
};
