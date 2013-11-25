/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where 
the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/
class Solution {
public:
    void combinations(vector<int> &candidates, int start, int target,vector<vector<int>> &result, vector<int> &current)
    {
        if(target==0)
        {
            result.push_back(current);
            return;
        }
        for(int i=start;i<candidates.size()&& target>=candidates[i];i++)
        {
            current.push_back(candidates[i]);
            combinations(candidates,i,target-candidates[i],result,current);
            current.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(),candidates.end());
        combinations(candidates,0,target,result,current);
        return result;
    }

};
