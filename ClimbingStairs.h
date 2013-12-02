/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 
*/
class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        while(n>=2)
        {
            int tmp = a;
            a = a + b;
            b = tmp;
            n--;
        }
        return a;
    }
};
