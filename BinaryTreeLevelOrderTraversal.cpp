/*
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

*/

class Solution {
public:
    /************* First Solution: Recursive Method ********/
    void BFS(TreeNode *root,vector<vector<int>> &result,int level)
    {
        if(!root)
        return;
        if(result.size()==level)
        {
            vector<int> L;
            L.push_back(root->val);
            result.push_back(L);
        }
        else
        result[level].push_back(root->val);
        
        BFS(root->left,result,level+1);
        BFS(root->right,result,level+1);
    }
    vector<vector<int> > levelOrder(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int>> result;
        if(!root)
        return result;
        BFS(root,result,0);
        return result;
    }
    
    /******Second Solution: Interative method ******/
    vector<vector<int> > levelOrder2(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int>> result;
        if(!root)
        return result;
        vector<TreeNode*> level;
        level.push_back(root);
        
        while(!level.empty())
        {
            vector<TreeNode*> next;
            vector<int> V;
            for(int i=0;i<level.size();i++)
            {
                TreeNode *curr = level[i];
                V.push_back(curr->val);
                if(curr->left)
                next.push_back(curr->left);
                if(curr->right)
                next.push_back(curr->right);
            }
            result.push_back(V);
            level = next;
        }
        return result;
    }
    
    
};
