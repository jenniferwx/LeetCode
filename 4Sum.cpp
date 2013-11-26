/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    
*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = num.size();
        vector<vector<int>> result;
        if(len<4)
        return result;
        sort(num.begin(),num.end());
        
        for(int i=0;i<len;i++)
        {
            if(i>0 && num[i]==num[i-1]) continue; // avoid duplicates
            for(int j=i+1;j<len;j++)
            {
                if(j>i+1 && num[j]==num[j-1]) continue; // avoid duplicates
                int TwoSum = num[i] + num[j];
                int SumLeft = target - TwoSum;
                int m = j+1;
                int n = len-1;
                while(m<n)
                {
                    int sum = num[m]+num[n];
                    if(sum == SumLeft)
                    {
                        vector<int> quadruplet(4);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[m];
                        quadruplet[3] = num[n];
                        result.push_back(quadruplet);
                        while(m<n && num[m+1]==num[m]) m++; // avoid duplicates
                        while(m<n && num[n-1]==num[n]) n--; // avoid duplicates
                        m++; // dont forget to increment m
                        n--;
                    }
                    else if(sum<SumLeft)
                    m++;
                    else 
                    n--;
                }
            }
        }
        return result;
    }
};
