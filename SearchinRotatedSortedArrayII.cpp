/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
class Solution {
public:
    bool search(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n==1 && A[0]!=target)
        return false;
        return BinarySearch(A,0,n-1,target);
    }
    bool BinarySearch(int A[],int left,int right,int target)
    {
        if(left>right)
        return false;
        int mid = (left+right)/2;
        if(A[mid]==target)
        return true;
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
            {
                if(A[mid]!=A[right])
                return BinarySearch(A,mid+1,right,target);
                else
                {
                    if(!BinarySearch(A,left,mid-1,target))
                    return BinarySearch(A,mid+1,right,target);
                    else
                    return true;
                }
            }
            else if(A[mid]==A[right])
            {
                if(A[mid]!=A[left])
                return BinarySearch(A,left,mid-1,target);
                else
                {
                    if(!BinarySearch(A,mid+1,right,target))
                    return BinarySearch(A,left,mid-1,target);
                    else
                    return true;
                }
            }
        }
       return false;
    }
};
