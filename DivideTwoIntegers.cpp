/*
Divide two integers without using multiplication, division and mod operator. 
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(dividend==0)
        return 0;
    //    assert(divisor!=0);
        int sign = 1;
        if(dividend<0)
        sign = -1;
        if(divisor<0)
        sign = sign*(-1);
        
        long long ld = abs((long long) dividend); //abs
        long long ls = abs((long long) divisor);
        long long count = 1;
        long long num = ls;
        long long result = 0;
        if(ls>ld)
        return 0;
        
        while(num < ld)
        {
            count<<=1;
            num<<=1;
        }
        
        while(num>=ls)
        {
            if(num<=ld)
            {
                ld -= num;
                result += count;
            }
            num>>=1;
            count>>=1;
        }
        return sign*result;
        
    }
};
