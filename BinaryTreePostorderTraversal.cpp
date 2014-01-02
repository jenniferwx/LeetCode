/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        return postorderTraversal_1(root); // iterative method
        return postorderTraversal_2(root); //recursive method
    }
    
    vector<int> postorderTraversal_1(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (cur||!stk.empty())
        {
            if(cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else if(!stk.empty())
            {
                if(stk.top()->right)
                cur = stk.top()->right;
                else
                {
                    TreeNode *child = stk.top();
                    res.push_back(child->val);
                    stk.pop();
                    while(!stk.empty()&&stk.top()->right==child)
                    {
                        res.push_back(stk.top()->val);
                        child = stk.top();
                        stk.pop();
                    }
                    if(stk.empty())
                    break;
                    else if (stk.top()->right!=child)
                    cur = stk.top()->right;
                }
            }
        }
        return res;
    }
    
    // second method
    vector<int> postorderTraversal_2(TreeNode *root)
    {
        vector<int> res;
        postorderRe(root,res);
        return res;
    }
    void postorderRe(TreeNode *root,vector<int> &res)
    {
        if(!root)
        return;
        postorderRe(root->left,res);
        postorderRe(root->right,res);
        res.push_back(root->val);
    }
};
