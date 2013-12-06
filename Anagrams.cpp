/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        int len = strs.size();
        vector<string> result;
        map<string,vector<int>> mymap;
        for(int i=0;i<len;i++)
        {
            string s = strs[i];
            sort(s.begin(),s.end());
            mymap[s].push_back(i);
        }
        map<string,vector<int>>::iterator iter = mymap.begin();
        for(;iter!=mymap.end();iter++)
        {
            vector<int> id = iter->second;
            if(id.size()>1)
            {
                for(int i=0;i<id.size();i++)
                result.push_back(strs[id[i]]);
            }
        }
        return result;
    }
};
