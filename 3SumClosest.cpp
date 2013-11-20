/*
Given an array S of n integers, find three integers in S such that the sum is closest to a 
given number, target. Return the sum of the three integers. You may assume that each input 
would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Written by Xi Wang
11/20/2013

*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = num.size();
        sort(num.begin(),num.end());
        int res = INT_MAX;
        for(int i=0;i<len-2;i++)
        {
            int j = i+1;
            int k = len-1;
            while(j<k)
            {
                int S = num[i]+num[j]+num[k];
                if(S == target)
                    return target;
                else if(S<target)
                j++;
                else
                k--;
                if(res == INT_MAX || abs(S-target)<abs(res-target))
                res = S;
            }
        }
        return res;
        
    }
};
