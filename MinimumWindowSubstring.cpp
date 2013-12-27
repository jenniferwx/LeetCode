/*
 Given a string S and a string T, find the minimum window in S which will contain all the characters 
 in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique 
minimum window in S. 
*/

class Solution {
public:
    string minWindow(string S, string T) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
       int m = S.size();
       int n = T.size();
       vector<int> TC(256);
       for (int i = 0; i < n; i++)
       TC[T[i]]++;
   
       int chs = 0;
       for (int i = 0; i < 256; i++)
           if (TC[i]) chs++;
       
       int pos = 0;
       int len = INT_MAX;
       
       int i = 0;
       for (int j = 0; j < m; j++) 
       {
           char ch = S[j];
           TC[ch]--;
           
           if (TC[ch] == 0) chs--;
           
           while (TC[S[i]] < 0) //注意是TC[S[i]] 而且是while
           { 
               TC[S[i]]++;
               i++;
           }
           
           if (chs == 0 && j - i + 1 < len) {
               len = j - i + 1;
               pos = i;
           }
       }
       return len == INT_MAX ? "" : S.substr(pos, len); 
    }
};
