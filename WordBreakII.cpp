/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence 
where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"]. 
*/

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        if (!wordBreakPossible(s, dict)) return res;
        wordBreakRe(s,dict,0,"",res);
        return res;
    }
    void wordBreakRe(string s, unordered_set<string> &dict,int start,string str,vector<string> &res)
    {
        if(start==s.size())
        {
            res.push_back(str);
            return;
        }
        
        if(start!=0)
        str.push_back(' ');
        for(int i=start;i<s.size();i++)
        {
            string word = s.substr(start,i-start+1);
            if(dict.find(word)!=dict.end())
            {
               // str += word;  //wrong
                wordBreakRe(s,dict,i+1,str+word,res); 
            }
        }
    }
    
    bool wordBreakPossible(const string &s, const unordered_set<string> &dict) {
        int N = s.size();
        bool canBreak[N+1];
        memset(canBreak, false, sizeof(canBreak));
        canBreak[0] = true;
        for (int i = 1; i <= N; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (canBreak[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    canBreak[i] = true;
                    break;
                }
            }
        }
        return canBreak[N];
    }
};
