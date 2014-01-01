/*
Given a binary tree, return the inorder traversal of its nodes' values.

Note: Recursive solution is trivial, could you do it iteratively?

*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        Inorder(root,result);
        return result;
    }
    void Inorder(TreeNode *root,vector<int> &result)
    {
        if(!root)
        return;
        Inorder(root->left,result);
        result.push_back(root->val);
        Inorder(root->right,result);
    }
    // iterative method
     vector<int> inorderTraversal_2(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty())
        {
            if (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else if (!stk.empty())
            {
                res.push_back(stk.top()->val);
                cur = stk.top()->right;
                stk.pop();
            }
        }
        return res;
    }
};
