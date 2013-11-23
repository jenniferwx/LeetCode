/*
Given a binary tree, return the inorder traversal of its nodes' values.

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
};
