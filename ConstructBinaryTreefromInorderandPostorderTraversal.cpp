/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
*/

// pay attention to the following mistakes I made.
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = inorder.size();
        return construct(inorder.begin(),postorder.begin(),len);
    }
    TreeNode *construct(vector<int>::iterator inorder, vector<int>::iterator postorder, int N)
    {
        if(N<=0)
        return  NULL;
        TreeNode *root = new TreeNode(*(postorder+N-1)); // should be *(postorder+N-1) not *(postorder+N)
        vector<int>::iterator it = find(inorder, inorder+N, *(postorder+N-1));
        int len = it-inorder;
        root->left = construct(inorder,postorder,len);
        root->right = construct(inorder+len+1,postorder+len,N-len-1); should be "postorder+len" not "postorder+len+1"
        return root;
    }
    
};
