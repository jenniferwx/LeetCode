/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int N = s.size();
        int dp[N][N];
        pair<int,int> res = make_pair(0,0); //start pos and end pos
        for(int k=0;k<N;k++) //length
        for(int i=0;i<N-k;i++)
        {
            if(k==0||k==1)
            dp[i][i+k] = s[i]==s[i+k];
            else
            dp[i][i+k] = (s[i]==s[i+k])?dp[i+1][i+k-1]:false;
            if(dp[i][i+k] && k+1>res.second)
            res = make_pair(i,k+1);
        }
        return s.substr(res.first,res.second);
    }
};
