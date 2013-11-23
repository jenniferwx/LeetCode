/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 

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
    TreeNode *constructTree(vector<int>::iterator preorder,vector<int>::iterator inorder,int N)
    {
        if(N<=0) return NULL;
        TreeNode *root = new TreeNode(*preorder);
        vector<int>::iterator it = find(inorder, inorder+N, *preorder);
        int len = it-inorder;
        root->left = constructTree(preorder+1,inorder,len);
        root->right = constructTree(preorder+len+1,inorder+len+1,N-len-1);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = preorder.size();
        return constructTree(preorder.begin(),inorder.begin(),len);
    }
};
