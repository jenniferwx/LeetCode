/*
 There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give? 

Written by Xi Wang
11/16/2013
*/

class Solution {
public:
    int candy(vector<int> &ratings) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = ratings.size();
        vector<int> candy(len,1);
        for(int i=1;i<len;i++)
        {
            if(ratings[i]>ratings[i-1])
            candy[i] = candy[i-1] +1;
        }
        for(int i=len-1;i>=1;i--)
        {
            if(ratings[i-1]>ratings[i] && candy[i-1]<=candy[i])
            candy[i-1] = candy[i] +1;
        }
        int result = 0;
        for(int i=0;i<len;i++)
        result += candy[i];
        
        return result;
    }
};
