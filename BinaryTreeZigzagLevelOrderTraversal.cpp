/*
iven a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

*/

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if(!root)
        return result;
        vector<TreeNode*> level;
        level.push_back(root);
        bool zig = false;
        while(!level.empty())
        {
            vector<TreeNode*> next;
            vector<int> V;
            for(int i=0;i<level.size();i++)
            {
                V.push_back(level[i]->val);
                if(level[i]->left)
                next.push_back(level[i]->left);
                if(level[i]->right)
                next.push_back(level[i]->right);
            }
            if(zig){
                reverse(V.begin(),V.end());
            }
            zig = !zig;//Do not forget
            result.push_back(V);
            level = next;
        }
    }
};
