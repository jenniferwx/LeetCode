/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        if(numRows<=0)
        return result;
        vector<int> next(1,1);
        result.push_back(next);
        for(int i=1;i<numRows;i++){
            next.push_back(0);
            for(int j=next.size()-1;j>=1;j--)
            {
                next[j] = next[j]+next[j-1];
            }
            result.push_back(next);
        }
        return result;
    }
};
