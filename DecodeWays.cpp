/*
 A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2. 
*/

class Solution {
public:
    int numDecodings(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int sum = 1,b = 1;
        int len = s.length();
        if(s.empty()||s[0]=='0')
        return 0;
        for(int i=1;i<len;i++)
        {
            int tmp = sum;
            if(s[i]=='0')  //IMPORTANT!!!!
            sum = 0;
            int num = (s[i-1]-'0')*10+(s[i]-'0');
            if(num>=10&&num<=26)
            {
                sum = sum + b;
            }
            b = tmp;
            if(b==0 && sum==0)
            break;
        }
        return sum;
    }
};
