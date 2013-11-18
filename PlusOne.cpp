/*
Given a number represented as an array of digits, plus one to the number.

Written by Xi Wang
11/17/2013
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = digits.size();
        if(len==0)
        return vector<int>(1,1);
        vector<int> result(len+1,0);
        int carry = 1;
        int k = len;
        for(int i = len-1;i>=0;i--)
        {
            int sum = digits[i]+carry;
            result[k--] = sum%10;
            carry = sum/10;
        }
        if(carry)
        result[0] = carry;
        if(carry==0)
        {
            for(int i=0;i<len;i++)
            result[i] = result[i+1];
            result.pop_back();
        }
        return result;
    }
};
