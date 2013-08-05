/*
 Author:     Xi Wang
 Date:       Aug 3, 2013
 Update:     Aug 3, 2013
 Problem:    Pow(x, n)
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_50
 Notes:
 Implement pow(x, n).
 
 Solution: recursion.
 */

class Solution {
public:
    double pow(double x, int n) {
        if (x == 1)
            return x;
        if (n < 0)
            return 1.0 / pow(x, -n);
        if (n == 0)
            return 1.0;
        if (n == 1)
            return x;
        if (x < 0)
            return (n % 2 == 0) ? pow(-x, n) : -pow(-x, n);     
        double half = pow(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else
            return x * half * half;
    }
};

