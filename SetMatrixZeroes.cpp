/*
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.
Follow up:

Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?


*/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
     //    setZeroes_1(matrix);
         setZeroes_2(matrix);
    }
    
    //solution1: space complexity O(m+n), time complexity O(mn)
    void setZeroes_1(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<bool> r(row,false);
        vector<bool> c(col,false);
        for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        {
            if(matrix[i][j]==0)
            {
                r[i] = true;
                c[j] = true;
            }
        }
        for(int i = 0;i <row;i++)
        for(int j = 0;j <col;j++)
        {
            if(r[i]==true || c[j] == true)
            matrix[i][j] = 0;
        }
    }
    
    //Solution 2: space complexity O(n)
    void setZeroes_2(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        bool firstRow = false;
        bool firstcolm =false;
        for(int i=0;i<row && !firstcolm;i++)
        firstcolm = (matrix[i][0]==0);
        for(int i=0;i<col && !firstRow;i++)
        firstRow = (matrix[0][i]==0);
        
        for(int i=1;i<row;i++)
        for(int j=1;j<col;j++)
        {
            if(matrix[i][j]==0)
            {
               matrix[i][0]=0;
               matrix[0][j]=0;
            }
        }
        
        for(int i=1;i<row;i++)
        {
            if(matrix[i][0]==0)
            {
                for(int j=1;j<col;j++)
                matrix[i][j]=0;
            }
        }
        for(int i=1;i<col;i++)
        {
            if(matrix[0][i]==0)
            {
                for(int j=1;j<row;j++)
                matrix[j][i]=0;
            }
        }
        if(firstRow)
        for(int i=0;i<col;i++)
        {
            matrix[0][i]=0;
        }
        if(firstcolm)
        for(int i=0;i<row;i++)
        {
            matrix[i][0]=0;
        }
 
    }
};
