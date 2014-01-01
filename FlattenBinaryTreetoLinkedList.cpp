/*
 Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

*/

class Solution {
public:
    void build(TreeNode *root)
    {
        if(!root)
        return;
        
        if(root->left)
        {
            build(root->left);
            TreeNode *curr = root->left;
            while(curr->right)
            {
                curr = curr->right;
            }
            curr->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }

        build(root->right);
    }
    void flatten(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        build(root);
    }
};
