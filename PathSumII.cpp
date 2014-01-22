/**
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
 */
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int>> result;
        vector<int> current;
        Calc_SUM(root,sum,result,current);
        return result;
    }
    void Calc_SUM(TreeNode *root, int sum, vector<vector<int>> &result, vector<int> current)
    {
        if(!root)
        return;
        if(!root->left && !root->right)
        {
            if(sum==root->val) // !
            {
                current.push_back(root->val);
                result.push_back(current);
                return;
            }
        }
        current.push_back(root->val);
        Calc_SUM(root->left,sum-root->val,result,current);
        Calc_SUM(root->right,sum-root->val,result,current);
        current.pop_back();
    }
};
