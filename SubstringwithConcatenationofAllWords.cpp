/*
 You are given a string, S, and a list of words, L, that are all of the same length. 
 Find all starting indices of substring(s) in S that is a concatenation of each word in L 
 exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter). 
*/
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        map<string,int> words;
        map<string,int> count;
        vector<int> result;
        int numW = L.size();
        if(numW == 0)
        return result;
        for(int i=0;i<numW;i++)
        words[L[i]]++;
        int WordSize = L[0].size();
        int i,j,len = S.length();
        // or use int(S.length())
        for(i=0;i<= len-numW*WordSize;i++)// 注意，这里用len，而不能用S.length(), S.length() is unsigned integer number
        {
            count.clear();
            for(j=0;j<numW;j++)
            {
                string w = S.substr(i+j*WordSize,WordSize);
                if(words.find(w)==words.end())
                break;
                count[w]++;
                
                if(count[w]>words[w])
                break;
            }
            if(j==numW)
            result.push_back(i);
        }
        return result;
    }
};
