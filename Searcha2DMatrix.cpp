/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return true.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
    //    return searchVector(matrix,target);
          return searchVector_2(matrix,target);
    }
    
    //SOLUTION 1:
    bool searchVector(vector<vector<int> > &matrix, int target)
    {
        if(matrix.empty() || matrix[0].empty())
        return false;
        int row = matrix.size();
        int col = matrix[0].size();
        int i=0,j=row-1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(matrix[mid][0]==target)
            return true;
            else if(matrix[mid][0]>target)
            j = mid-1; //j-1
            else
            i = mid+1; //i+1
        }
        row = j;
        if(row<0)
        return false;
        i =0, j = col-1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(matrix[row][mid]==target)
            return true;
            else if(matrix[row][mid]>target)
            j = mid-1;
            else
            i = mid+1;
        }
        return false;
    }
    
    
    // SOLUTION 2:
    bool searchVector_2(vector<vector<int> > &matrix, int target)
    {
        if(matrix.empty() || matrix[0].empty())
        return false;
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0, j = col-1;
        
        while(i<row &&j>=0)
        {
            if(matrix[i][j]==target)
            return true;
            else if(matrix[i][j]>target)
            j--;
            else
            i++;
        }
        return false;
    }
};
