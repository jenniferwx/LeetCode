/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node 
down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!root)
        return 0;
        return DFS(root);
    }
    int DFS(TreeNode *root)
    {
        if(!root)
        return 0;
        int minLeft = DFS(root->left);
        int minRight = DFS(root->right);

        if(minLeft==0)
        return minRight+1;
        else if(minRight==0)
        return minLeft+1;
        else
        return min(minLeft+1, minRight+1);
    }
};
