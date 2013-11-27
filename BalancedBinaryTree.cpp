/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two 
subtrees of every node never differ by more than 1. 
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
    bool isBalanced(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return BalanceSubTree(root);
    }
    int Depth(TreeNode *root)
    {
        if(!root)
        return 0;
        else
        return max(Depth(root->left),Depth(root->right))+1;
    }
    bool BalanceSubTree(TreeNode *root)
    {
        if(!root)
        return true;
        int Left = Depth(root->left);
        int Right = Depth(root->right);
        if(abs(Left-Right)>1)
        return false;
        else
        return BalanceSubTree(root->left) && BalanceSubTree(root->right);
    }
};
