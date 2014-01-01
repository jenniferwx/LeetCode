/*
 Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false. 
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if(len3!=len1+len2)
        return false;

        vector<vector<bool>> match(len1+1,vector<bool>(len2+1,false));
        match[0][0] = true;
        for(int i=1;i<=len1;i++)
        {
            if(s1[i-1]==s3[i-1])
            match[i][0]=true;
            else
            break;
        }
        for(int j=1;j<=len2;j++)
        {
            if(s2[j-1]==s3[j-1])
            match[0][j]=true;
            else
            break;
        }
        for(int i=1;i<=len1;i++)
        for(int j=1;j<=len2;j++)
        {
            if(s1[i-1]==s3[i+j-1])
            match[i][j] = match[i-1][j]||match[i][j];
            if(s2[j-1]==s3[i+j-1])
            match[i][j] = match[i][j-1]||match[i][j];
        }
        return match[len1][len2];
    }
};
