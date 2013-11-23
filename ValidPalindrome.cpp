/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 

*/
class Solution {
public:
    bool isValid(char &a)
    {
        if(a>='a' && a<='z' || a>='0' && a<='9')
        return true;
        if(a>='A' && a<='Z')
        {
            a = a+32;
            return true;
        }
        else
        return false;
    }
    bool isPalindrome(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = s.size();
        int i=0,j=len-1;
        while(i<j)
        {
            while(!isValid(s[i])&& i<j) i++;
            while(!isValid(s[j])&& i<j) j--;
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
};
