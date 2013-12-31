/*
 Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res(1, vector<int>());
        sort(S.begin(), S.end());
        vector<int> set;
        int N = S.size();
        for (int l = 1; l <= N; ++l)
            subsetsWithDupRe(S, l, 0, set, res);
        return res;
    }

    void subsetsWithDupRe(vector<int> &S, int L, int start, vector<int> &set, vector<vector<int>> &res)
    {
        int N = S.size(), M = set.size();
        if (M == L) {
            res.push_back(set);
            return;
        }
        for (int i = start; i <= N - (L - M); ++i) {
            if (i > start && S[i] == S[i-1]) continue;
            set.push_back(S[i]);
            subsetsWithDupRe(S, L, i + 1, set, res);
            set.pop_back();
        }
    }
    
    // Second Solution: iterative method
      vector<vector<int> > subsetsWithDup2(vector<int> &S) {
        vector<vector<int>> result;
        vector<vector<int>> save;
        if(S.empty())
        return result;
        sort(S.begin(),S.end());
        result.push_back(vector<int>());
        result.push_back(vector<int>(1,S[0]));
        save.push_back(vector<int>(1,S[0]));
        int len = S.size();
        for(int i=1;i<len;i++)
        {
            if(S[i]!=S[i-1])
            {
                save.clear();
                for(int j=result.size()-1;j>=0;j--)
                {
                    result.push_back(result[j]);
                    result.back().push_back(S[i]);
                    save.push_back(result.back());
                }
            }
            else
            {
                for(int j=save.size()-1;j>=0;j--)
                {
                    save[j].push_back(S[i]);
                    result.push_back(save[j]);
                }
            }
        }
        return result;
        
    }
};
