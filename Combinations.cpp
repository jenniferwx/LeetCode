/*
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

Written by Xi Wang

*/

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int>> result;
        vector<int> comb;
        DFS(1,n,k,result,comb);
        return result;
    }
    void DFS(int start, int n, int k, vector<vector<int>> &result, vector<int> curr)
    {
        int m = curr.size();
        if(m==k)
        {
            result.push_back(curr);
            return;
        }
        
        for(int i=start;i<=n-(k-m)+1;i++)
        {
            curr.push_back(i);
            DFS(i+1,n,k,result,curr); 
            curr.pop_back();
        }
    }
};
