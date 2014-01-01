/*
 Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value. 
*/
class Solution {
public:
    bool check(TreeNode *p,TreeNode *q)
    {
        if(!p&&!q)
        return true;
        if(!p||!q)
        return false;
        return (p->val==q->val)&&check(p->left,q->left)&&check(p->right,q->right);
    }
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!p&&!q)
        return true;
        if(!p||!q)
        return false;
        return check(p,q);
        
    }
};
