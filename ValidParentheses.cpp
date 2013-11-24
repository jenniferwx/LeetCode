/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input 
string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/
class Solution {
public:
    bool isValid(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        stack<char> mystack;
        int len = s.size();
        if(len<=0)
        return true;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            mystack.push(s[i]);
            else
            {
                if(mystack.empty()) //need to check first
                return false;
                char top = mystack.top();
                mystack.pop();
                if(s[i]==')')
                {
                    if(top!='(')
                    return false;
                }
                else if(s[i]==']')
                {
                    if(top!='[')
                    return false;
                }
                else if(s[i]=='}')
                {
                    if(top!='{')
                    return false;
                }
            }
        }
        return mystack.empty();
        
    }
};
