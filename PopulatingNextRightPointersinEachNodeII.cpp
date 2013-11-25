/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL


*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode *parent)
    {
        if(!parent)
        return NULL;
        else if(parent->left)
        return parent->left;
        else if(parent->right)
        return parent->right;
        else
        return GetNext(parent->next);
    }
    void connect(TreeLinkNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!root)
        return;
      //  root->next = NULL;
        
        TreeLinkNode *left =root;
        while(left)
        {
            root = left;
            while(root)
            {
                if(root->left && root->right)
                {
                    root->left->next = root->right;
                    root->right->next = GetNext(root->next);
                }
                else if(root->left || root->right)
                GetNext(root)->next = GetNext(root->next);
                root = root->next;
            }
            left = GetNext(left);
        }
        return;
    }
};
