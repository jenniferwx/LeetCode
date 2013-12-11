/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty())
        {
            if (cur)
            {
                res.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }
            else if (!stk.empty())
            {
                cur = stk.top()->right;
                stk.pop();
            }
        }
        return res;
        
    }
};
