/*
Author: Xi Wang
Date: Aug 5, 2013
Problem: Sqrt(x)
Notes:
Implement int sqrt(int x).
Compute and return the square root of x.

Solution: 1. Binary search in range [0, x / 2 + 1].
2. Newton iteration method. x(i+1) = (x(i) + n/x(i)) / 2.
*/

class Solution {
public:
    int sqrt_1(int x) {
        long long i = 0;
        long long j = x / 2 + 1;
        while (i <= j)
        {
            long long mid = (i + j) / 2;
            long long sq = mid * mid;
            if (sq == x) return mid;
            else if (sq < x) i = mid + 1;
            else j = mid - 1;
        }
        return j;
    }

    int sqrt_2(int x) {
        if (x == 0) return 0;
        double last = 0;
        double res = 1.0;
        while (res != last)
        {
            last = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};
