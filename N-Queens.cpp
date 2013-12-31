/*
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' 
both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:
*/
class Solution {
public:
    bool isValid(int row, vector<int> place)
    {
        for(int i=0;i<row;i++)
        {
            int diff=abs(place[i]-place[row]);
            if(diff==0||diff==row-i)
            return false;
        }
        return true;
    }
    void placeQueens(int row, int n, vector<vector<string>> &result, vector<int> &place)
    {
        if(row==n)
        {
            vector<string> vec;
            for(int i=0;i<n;i++)
            {
                string tmp(n,'.');
                tmp[place[i]]='Q';
                vec.push_back(tmp);
            }
            result.push_back(vec);
            return;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                place[row]=i;
                if(isValid(row,place))
                placeQueens(row+1,n,result,place);
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> place(n);
        placeQueens(0,n,result,place);
        return result;
    }
};
