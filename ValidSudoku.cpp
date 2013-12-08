/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A partially filled sudoku which is valid.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int row = board.size();
        int col = board[0].size();
        for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        {
            if(board[i][j]!='.')
            {
                if(!isValid(board,i,j))
                return false;
            }
        }
        return true;
    }
    bool isValid(vector<vector<char> > &board, int r, int c)
    {
        int row = board.size();
        int col = board[0].size();
        if(r<0 ||r>=row || c<0 || c>=col)
        return false;
        
        //check row
        for(int i=0;i<row;i++)
        {
            if(board[i][c]==board[r][c] && i!=r)
            return false;
        }
        
        //check column
        for(int i=0;i<col;i++)
        {
            if(board[r][i]==board[r][c] && i!=c)
            return false;
        }
        
        //check 3*3 block
        const int rmin = r / 3 * 3;  
        const int cmin = c / 3 * 3;
        for(int i=rmin;i<rmin+3;i++)
        for(int j=cmin;j<cmin+3;j++)
        {
            if(i!=r&&j!=c && board[i][j]==board[r][c])
            return false;
        }
        return true;
    }
};
