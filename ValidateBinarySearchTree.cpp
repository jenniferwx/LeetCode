/*
 Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/
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
    bool isValidBST(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return Validation(root,INT_MIN,INT_MAX);
    }
    bool Validation(TreeNode *root, int min, int max)
    {
        if(!root)
        return true;
        
        bool ValLeft = Validation(root->left,min,root->val);
        bool ValRight = Validation(root->right,root->val,max);
        if(ValLeft && ValRight)
        return (root->val>min && root->val<max);
        else
        return false;
    }
};
