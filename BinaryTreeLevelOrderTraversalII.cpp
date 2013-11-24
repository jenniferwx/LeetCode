/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7]
  [9,20],
  [3],
]

*/
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int>> result;
        if(!root)
        return result;

        queue<TreeNode*> level;
        level.push(root);
        while(!level.empty())
        {
            queue<TreeNode*> N;
            result.push_back(vector<int>());
            while(!level.empty())
            {
                TreeNode* current = level.front();
                result.back().push_back(current->val);
                level.pop();
                if(current->left)
                N.push(current->left);
                if(current->right)
                N.push(current->right);
            }
            level = N;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
