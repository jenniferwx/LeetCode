/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0 
*/
class Solution {
public:
    int biSearch(int A[],int left,int right, int target)
    {
        if(left>right)
        {
            return left;
        }
            
        int mid = (left+right)/2;
        if(A[mid]==target)
        return mid;
        else if(A[mid]<target)
        return biSearch(A,mid+1,right,target);
        else if(A[mid]>target)
        return biSearch(A,left,mid-1,target);
    }
    int searchInsert(int A[], int n, int target) {
        if(n==0)
        return 0;
        return biSearch(A,0,n-1,target);
    }
};
