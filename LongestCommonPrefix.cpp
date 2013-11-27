/*
Write a function to find the longest common prefix string amongst an array of strings. 
*/
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = strs.size();
        string result = "";
        if(len<=0)
        return result;
        int len1 = strs[0].size();
        string str0 = strs[0];
        int i,j;
        for(i=0;i<len1;i++)
        {
            char ch = str0[i];
            for(j=1;j<len;j++)
            {
                string current = strs[j];
                if(current[i]!=ch)
                break;
            }
            if(j==len)
            result += ch;
            else
            break;
        }
        return result;
    }
};
