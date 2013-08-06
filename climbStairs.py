"""
Author: Xi Wang
Date: Aug 5, 2013
Problem: Climbing Stairs
Notes:
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Solution: Clime one step from last stair or clime 2 steps from the last last stair.
"""

import numpy as np

def climbStairs(num):
    last=1
    lastlast=1
    for i in range(2,num):
       step = last+lastlast
       lastlast=last
       last = step
       
    return last   
