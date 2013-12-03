/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest 
substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest 
substring is "b", with the length of 1.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = s.size();
        if(len==0)
        return 0;
        vector<int> mymap(256,-1);
        int maxLen = 0, end = 0;
        for(int i=0;i<len;i++)
        {
            char ch = s[i];
      			if(end <= mymap[ch]) // Notice: here should be "<=" not "<"
      			{
      			    maxLen = max(maxLen, i-end);
      			    end = mymap[ch] + 1;
      			}
            mymap[ch] = i;
        }
        return max(maxLen,len-end);
    }
};
