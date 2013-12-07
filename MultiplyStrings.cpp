/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        string res(len1+len2,'0');
        for(int i=len1-1;i>=0;i--)
        {
            int carry = 0;
            for(int j=len2-1;j>=0;j--)
            {
                int k = i+j+1;
                int num = (num1[i]-'0') * (num2[j]-'0') + (res[k]-'0') + carry;
                res[k] = num%10 +'0';
                carry =num/10;
            }
            res[i] = carry + '0';
        }
        while(res.size()>1 && res[0]=='0')
        res.erase(res.begin());
        
        return res;
    }
};
