/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle 
containing all ones and return its area. 
*/

class Solution {
public:
    int checkMax(vector<int> V)
    {
        int len = V.size();
        int max = -1, sum=0;
        for(int i = 0;i<len;i++)
        {
            int right = i;
            while(V[right+1]>=V[i]&&(right+1)<len)
            right++;
            int left = i;
            while(V[left-1]>=V[i]&&(left-1)>=0)
            left--;
            sum = (right-left+1)*V[i];
            if(sum>max)
            max = sum;
        }
        return max;
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(matrix.empty())
        return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> sum(n,0);
        int Max = -1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                sum[j] +=1;
                else
                sum[j] = 0;
            }
            int result = checkMax(sum);
            if(result>Max)
            Max = result;
        }
        return Max;
        
    }
};
