/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see 
below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are 
responsible to gather all the input requirements up front. 
*/


class Solution {
public:
    int atoi(const char *str) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        long long result=0;
        if(!str)
        return result;
        while(*str==' ')   str++;
        bool negative = false;
        if(*str=='-' || *str=='+')
        {
            negative = *str=='-';
            str++;
        }
        
        while(*str>='0' && *str<='9') // need to check
        {
            result = result*10+(*str-'0');
            str++;
        }
        
        if(negative)
        result = -1*result;
        if(result>INT_MAX)       result = INT_MAX;
        if(result<INT_MIN)       result = INT_MIN;
        
        return (int)result;
        
    }
};
