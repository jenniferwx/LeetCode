/*
 Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings 
 recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1. 

*/

class Solution {
public:
    // Time Limit Exceeded
    bool isScramble(string s1, string s2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1!=len2)
        return false;
        return check(s1,s2);
    }
    bool check(string s1,string s2)
    {
        int len = s1.size();
        if(!isValid(s1,s2)) return false; //important
        if(len==1 && len==0) return true;
        
        for(int i=1;i<len;i++)
        {
            if((check(s1.substr(0,i),s2.substr(0,i)) && check(s1.substr(i,len-i),s2.substr(i,len-i)))
            || (check(s1.substr(0,i),s2.substr(len-i,i)) && check(s1.substr(i,len-i),s2.substr(0,len-i))))
            return true;
        }
        return false;
    }
    bool isValid(string s1, string s2)
    {
        vector<int> check(256,0);
        for(int i=0;i<s1.length();i++) check[s1[i]]++;
        for(int i=0;i<s2.length();i++) check[s2[i]]--;
        for(int i=0;i<256;i++)
        {
            if(check[i]!=0) // check[i]>0 will be super slow, will cause time limit exceed
            return false;
        }
        return true;
    }
    
};
