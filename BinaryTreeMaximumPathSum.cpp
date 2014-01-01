/*
 Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6. 
*/

class Solution {
public:
    int submax(TreeNode *root, int &mysum)
    {
        if(!root)
        return 0;
        int V = root->val;
        int left = submax(root->left,mysum);
        int right = submax(root->right,mysum);
        if(left>0)
        V +=left;
        if(right>0)
        V +=right;
        mysum = max(V,mysum);
        return max(root->val,max(root->val+left,root->val+right));
    }
    int maxPathSum(TreeNode *root) {
        int mysum = root->val; 
        int maxsum=submax(root,mysum);
        return max(maxsum,mysum);
    }
};
