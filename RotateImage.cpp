/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
      //  rotate_1(matrix);
       rotate_2(matrix);
    }
    //method1: O(n^3)
    void rotate_1(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; i++)
            for (int j = 0; j < n / 2; j++)
                rotateElement(matrix, i, j);
    }
    void rotateElement(vector<vector<int> > &matrix, int row, int col)
    {
        int temp = matrix[row][col];
        for (int i = 0; i < 3; i++)
        {
            int c = row;
            int r = matrix.size() - 1 - col;
            matrix[row][col] = matrix[r][c];
            row = r;
            col = c;
        }
        matrix[row][col] = temp;
    }
    
    //method 2: O(n^2)
    void rotate_2(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i =0;i<row;i++)
        for(int j =i+1;j<col;j++) // j starts from i+1
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
        for(int i=0;i<row;i++)
        for(int j=0;j<col/2;j++)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][col-1-j];
            matrix[i][col-1-j] = tmp;
        }
    }
};
