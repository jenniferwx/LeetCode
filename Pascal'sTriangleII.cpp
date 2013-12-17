/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space? 
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result(1,1);
        for(int i=1;i<=rowIndex;i++)
        {
            result.push_back(0);
            for(int j=result.size()-1;j>=1;j--)
            result[j] = result[j]+result[j-1];
        }
        return result;
    }
};
