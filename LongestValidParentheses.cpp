/*
Given a string containing just the characters '(' and ')', find the length of the longest valid 
(well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = s.length();
        if(len<2)
        return 0;
        int count = 0;
        int begin = len;
        
        //解题思路： 保存下'('最远出现的位置
        stack<int> mystack;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='(')
            mystack.push(i);
            else if(!mystack.empty())
            {
                int tmp = mystack.top();
                mystack.pop(); 
                begin = begin<tmp?begin:tmp;
                if(mystack.empty())
                count = i-begin+1>count?i-begin+1:count;
                else
                count = i-mystack.top()>count?i-mystack.top():count;
            }
            else
            begin = i+1;  //关键！
        }
        return count;
    }
};
