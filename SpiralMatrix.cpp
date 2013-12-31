/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5]. 
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        if(matrix.empty())
        return result;
        int imax = matrix.size()-1;
        int jmax = matrix[0].size()-1;
        int imin=0,jmin=0;
        
        while(true)
        {
            for(int j=jmin;j<=jmax;j++)
            result.push_back(matrix[imin][j]);  //注意
            if(++imin>imax) break;  
            
            for(int i = imin;i<=imax;i++) 
            result.push_back(matrix[i][jmax]);
            if(--jmax<jmin) break;
            
            for(int j=jmax;j>=jmin;j--)
            result.push_back(matrix[imax][j]);
            if(--imax<imin) break;
            
            for(int i=imax;i>=imin;i--)
            result.push_back(matrix[i][jmin]);
            if(++jmin>jmax) break;
        }
        return result;
    }
};
