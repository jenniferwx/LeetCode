/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]


Written by Xi Wang
11/17/2013


*/

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int>> result(n,vector<int>(n));
        int rMax = n-1, cMax = n-1;
        int rMin = 0, cMin = 0;
        int i, j,N=1;
        while(N<=n*n)
        {
            for(j=cMin;j<=cMax;j++)  result[rMin][j] = N++;
            if(++rMin>rMax) break;
            for(i=rMin;i<=rMax;i++) result[i][cMax] = N++;
            if(--cMax<cMin) break;
            for(j=cMax;j>=cMin;j--) result[rMax][j] = N++;
            if(--rMax<rMin) break;
            for(i=rMax;i>=rMin;i--) result[i][cMin] = N++;
            if(++cMin>cMax) break;
        }
        return result;
    }
};
