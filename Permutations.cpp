/*
 Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
*/
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int> > permute(vector<int> &num) {
        int N = num.size();
        vector<int> curr;
        vector<bool> avail(N,true);
        GetPermute(num,avail,curr);
        return result;
    }
    void GetPermute(vector<int> &num, vector<bool> &avail, vector<int>& curr)
    {
        if(curr.size()==num.size())
        {
            result.push_back(curr);
        }
        for(int i=0;i<num.size();i++)
        {
            if(avail[i])
            {
                curr.push_back(num[i]);
                avail[i] = false;
                GetPermute(num,avail,curr);
                curr.pop_back();
                avail[i] = true;
            }
        }
        
    }
};
