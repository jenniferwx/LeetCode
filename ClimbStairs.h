 /*
Author: Xi Wang
Date: Aug 5, 2013
Problem: Climbing Stairs
Notes:
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Solution: Clime one step from last stair or clime 2 steps from the last last stair.
*/ 
 
 int climbStairs(int n) {
        // Dynamic programming
        int last=1;
        int lastlast=1;
        for(int i=2;i<=n;i++)
        {
            int step = last+lastlast;
            lastlast=last;
            last = step;
        }
        return last;
      
      /*  int count;
        if(n==1)
        return 1;
        if(n==0)
        return 1;
        else count = climbStairs(n-1)+climbStairs(n-2);
        return count;*/ // Time limit exceed
    }
