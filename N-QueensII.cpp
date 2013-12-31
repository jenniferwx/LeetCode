/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/
class Solution {
public:
    bool check(int row, int* place)
    {
        for (int i = 0; i < row; ++i)
        {
            int diff = abs(place[i] - place[row]);
            if (diff == 0 || diff == row - i)
                return false;
        }
        return true;
    }
    
    void placeQueens(int row, int n, int &count, int* place)
    {
        if (row == n)
        {
            ++count;
            return;
        }
        
        for (int i = 0; i < n; ++i)
        {
            place[row] = i;
            if (check(row, place))
                placeQueens(row+1, n, count, place);
        }
    }
    
    int totalNQueens(int n) {
        int* place = new int[n];
        int count = 0;
        placeQueens(0, n, count, place);
        return count;
    }
};
