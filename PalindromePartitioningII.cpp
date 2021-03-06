/*
 Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. 

Solution: DP
*/
class Solution {
public:
    int minCut(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = s.length();
        bool isP[len];
        int dp[len];
        dp[0] = 0;
        for(int i=1;i<len;i++)
        {
            isP[i] = true;
            dp[i] = dp[i-1] +1;
            for(int j=0;j<i;j++)
            {
                isP[j] = (s[i]==s[j])?isP[j+1]:false;  // isP[j] == true -> [j...i] is a palindrome
                                                      // isP[j+1] == true -> [j+1...i-1] is a palindrome
                if (isP[j])
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j-1] + 1); // dp[i] -> minCount for [0...i]
            }
        }
        
        return dp[len-1];
    }
};
