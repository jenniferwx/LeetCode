/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some 
(can be none) of the characters without disturbing the relative positions of the remaining characters. 
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/
class Solution {
public:
    int numDistinct(string S, string T) {
        int L1 = S.size();
        int L2 = T.size();
        int dp[L1+1][L2+1];
        dp[0][0] = 1;
        
        for(int i=1;i<=L1;i++)
            dp[i][0] = 1;
        for(int i=1;i<=L2;i++)
            dp[0][i] = 0;
            
        for(int i=1;i<=L1;i++)
        for(int j=1;j<=L2;j++)
        {
            if(S[i-1]==T[j-1])
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else
            dp[i][j] = dp[i-1][j];
        }
        return dp[L1][L2];

    }
};
