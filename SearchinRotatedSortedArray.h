/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Written by Xi Wang
11/19/2013

*/

class Solution {
public:
    int BinarySearch(int A[],int left,int right,int target)
    {
        if(left>right)
        return -1;
        int mid = (left+right)/2;
        if(A[mid]==target)
        return mid;
        else
        {
            if(A[left]<A[mid])
            {
                if(target<=A[mid] && target>=A[left])
                {
                    return BinarySearch(A,left,mid-1,target);
                }
                else
                return BinarySearch(A,mid+1,right,target);
            }
            else if(A[mid]<A[right])
            {
                if(target>=A[mid] && target<=A[right])
                return BinarySearch(A,mid+1,right,target);
                else
                return BinarySearch(A,left,mid-1,target);
            }
            else if(A[mid]==A[left])
            return BinarySearch(A,mid+1,right,target);
            else if(A[mid]==A[right])
            return BinarySearch(A,left,mid-1,target);
        }
       return -1;
        
    }
    int search(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n==1 && A[0]!=target)
        return -1;
        return BinarySearch(A,0,n-1,target);
    }
};
