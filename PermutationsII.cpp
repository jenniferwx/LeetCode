/*
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1]. 
SOLUTION: dfs
*/

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int> > permuteUnique(vector<int> &num) {
        int len = num.size();
        vector<int> curr;
        vector<bool> avail(len,true);
        sort(num.begin(),num.end()); //This is important
        permutations(num,avail,curr);
        return result;
    }
    void permutations(vector<int> &num,vector<bool> &avail,vector<int> &curr)
    {
        if(num.size()==curr.size())
        {
            result.push_back(curr);
            return;
        }
        
        int lastIDX = -1;
        for(int i=0;i<num.size();i++)
        {
            if(avail[i]==false) continue;
            if(lastIDX!=-1 &&num[i]==num[lastIDX]) continue;
            
            curr.push_back(num[i]);
            avail[i] = false;
            permutations(num,avail,curr);
            curr.pop_back();
            avail[i] = true;
            lastIDX = i;
        }
    }
};
