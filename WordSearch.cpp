/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" 
cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

Solution: DFS
*/
class Solution {
public:
    bool search(vector<vector<char>> &board, int r,int c, int k, string word, vector<vector<bool>> &available)
    {
        int row = board.size();
        int col = board[0].size();
        if(word.length()==k)  return true; //should check this first
        if(r<0 ||r>=row || c<0 || c>=col) return false;
        if(board[r][c]!=word[k]||available[r][c]==false) return false;
        
        available[r][c] = false;
        
        if(search(board,r+1,c,k+1,word,available)) return true;
        if(search(board,r-1,c,k+1,word,available)) return true;
        if(search(board,r,c+1,k+1,word,available)) return true;
        if(search(board,r,c-1,k+1,word,available)) return true; 
        
        available[r][c] = true;
        
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int row = board.size();
        if(row<=0)
        return false;
        int col = board[0].size();
        vector<vector<bool>> available(row, vector<bool>(col,true));
        for(int i = 0; i<row; i++)
        for(int j = 0; j<col; j++)
        {  
            if(search(board,i,j,0,word,available))
            return true;
        }
        return false;
    }
};
