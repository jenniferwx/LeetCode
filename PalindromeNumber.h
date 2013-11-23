/*
Determine whether an integer is a palindrome. Do this without extra space.

*/
class Solution {
public:
    bool isPalindrome(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(x<0)
        return false;
        long long base = 1; // notice
        while(base<x)
        {
            base = base*10;
        }
        base/=10;
        while(base>0)
        {
            int a = x%10;
            int b = x/base;
            if(a!=b)
            return false;
            x = x%base;
            x = x/10;
            base = base/100;
        }
        return true;
    }
};
