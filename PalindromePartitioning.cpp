/*
 Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
Written by Xi Wang
11/14/2013

Solution: DFS
*/


class Solution {
public:
    bool check(string s)
    {
        int len = s.length();
        if(len==0)
        return false;
        if(len==1)
        return true;
        int i=0,j=len-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            return false;
            else
            {
                i++;
                j--;
            }
        }
        return true;
        
    }
    void stringpartition(string s, vector<vector<string>> &result, vector<string> &V)
    {
        if(s.length()==0)
        {
            result.push_back(V);
            return;
        }
        int len = s.length();
        for(int i=0;i<len;i++)
        {
            string tp = s.substr(0,i+1);
            if(check(tp))
            {
                V.push_back(tp);
                stringpartition(s.substr(i+1),result,V);
                V.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = s.length();
        vector<vector<string>> result;
        vector<string> tmp;
        stringpartition(s,result,tmp);
        return result;
        
    }
};
