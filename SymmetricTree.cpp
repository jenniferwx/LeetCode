/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively. 
*/
class Solution {
public:
    bool Check(TreeNode *left, TreeNode *right)
    {
        if(!left&&!right)
        return true;
        if(!left||!right)
        return false;
        
        return (left->val==right->val)&&Check(left->left,right->right)&&Check(left->right,right->left);
        
    }
    bool isSymmetric(TreeNode *root) {
        if(!root)
        return true;
        return Check(root,root);
    }
    
    //iterative method:
    bool isSymmetric_2(TreeNode *root) {
        if (!root) return true;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty())
        {
            TreeNode *t1 = q.front(); q.pop();
            TreeNode *t2 = q.front(); q.pop();
            if (!t1 && !t2) continue;
            if (!t1 || !t2 || t1->val != t2->val)
                return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};
