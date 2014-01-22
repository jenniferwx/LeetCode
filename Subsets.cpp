/*
 Given a set of distinct integers, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = S.size();
        vector<vector<int>> result;
        if(len<=0)
        return result;
        sort(S.begin(),S.end());
        result.push_back(vector<int>());
        for(int i=0;i<len;i++)
        {
            for(int j = result.size()-1;j>=0;j--)
            {
                result.push_back(result[j]);
                result.back().push_back(S[i]);
            }
        }
        return result;
    }
    // Recursive method:
    vector<vector<int> > subsets_2(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = S.size();
        vector<vector<int>> result(1,vector<int>());
        sort(S.begin(),S.end());
        vector<int> set;
        for(int i=1;i<=len;i++)
        subsetsRe(S,0,i,result,set);
        return result;
    }
    void subsetsRe(vector<int> &S, int start, int len, vector<vector<int>> &result, vector<int> &current)
    {
        int N = current.size();
        int M = S.size();
        if(N==len)
        {
            result.push_back(current);
            return;
        }
        for(int i=start;i<=M-(len-N);i++)
        {
            current.push_back(S[i]);
            subsetsRe(S,i+1,len,result,current);
            current.pop_back();
        }
    }
};
