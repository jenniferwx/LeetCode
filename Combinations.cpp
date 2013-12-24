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
    
    // Second Solution
    vector<vector<int>> GetNext(int n,vector<vector<int>> &cur)
    {
        vector<vector<int>> result;
        for(int i=0;i<cur.size();i++)
        {
            for(int j=cur[i].back()+1;j<=n;j++)
            {
                result.push_back(cur[i]);
                result.back().push_back(j);
            }
        }
        return result;
        
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        for(int i=1;i<=n;i++)
        {
            result.push_back(vector<int>());
            result.back().push_back(i);
        }
        for(int i=1;i<k;i++)
        result = GetNext(n,result);
        
        return result;
        
    }
};
