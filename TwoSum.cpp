/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 

Written by Xi Wang
11/17/2013

*/

struct Node
{
    int val;
    int indx;
    Node(){};
    Node(int a, int b): val(a),indx(b){};
};
bool isLess(const Node &a, const Node &b)
{
    return a.val<b.val;
}
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = numbers.size();
        vector<int> result(2);
        if(len<2)
        return result;
        vector<Node> Nodes(len);
        for(int i=0;i<len;i++)
        {
            Nodes[i] = Node(numbers[i],i+1);
        }
        sort(Nodes.begin(),Nodes.end(),isLess);
        
        int i=0,j=len-1;
        while(i<j)
        {
            if(Nodes[i].val+Nodes[j].val==target)
            {
                result[0] = min(Nodes[i].indx,Nodes[j].indx);
                result[1] = max(Nodes[i].indx,Nodes[j].indx);
                break;
            }
            else if(Nodes[i].val+Nodes[j].val<target)
            i++;
            else
            j--;
        }
        return result;
    }
};
