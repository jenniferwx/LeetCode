/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Written by Xi Wang
11/21/2013
*/

class Solution {
public:
    int romanToInt(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        unordered_map<char, int> roman;
        roman['M'] = 1000;
        roman['D'] = 500;
        roman['C'] = 100;
        roman['L'] = 50;
        roman['X'] = 10;
        roman['V'] = 5;
        roman['I'] = 1;
        
        int sum = 0,len = s.length();
        for(int i=0;i<len;i++)
        {
            if(i<len-1 && roman[s[i]]<roman[s[i+1]])
            sum -= roman[s[i]];
            else
            sum += roman[s[i]];
        }
        return sum;
        
    }
};
