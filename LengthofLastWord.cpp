/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5. 
*/
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = strlen(s);
        int count=0;
        for(int i=len-1;i>=0;i--)
        {
            if(s[i]!=' ') count++;
            else if(count>0) 
            break;
        }
        return count;
    }
};
