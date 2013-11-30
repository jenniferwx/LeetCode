/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
