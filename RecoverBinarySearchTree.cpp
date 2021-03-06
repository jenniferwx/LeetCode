/*
 Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

OJ's Binary Tree Serialization:

The serialization of a binary tree follows a level order traversal, where '#' signifies a 
path terminator where no node exists below.

Here's an example:

   1
  / \
 2   3
    /
   4
    \
     5

The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}". 

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
 TreeNode *tp1;
 TreeNode *tp2;
 TreeNode *previous;
class Solution {
public:
    void recoverTree(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        previous = tp1 = tp2 = NULL;
        DFS(root);
        swap(tp1->val,tp2->val);
    }
    void DFS(TreeNode *root)
    {
        if(!root)
        return;
        DFS(root->left);
        if(previous && root->val<previous->val)
            tp1? tp2 = root:tp1 = previous,tp2=root;
        else
            previous = root;    
        DFS(root->right);
    }
}
