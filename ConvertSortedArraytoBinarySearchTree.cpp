/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
Written by Xi Wang
11/17/2013

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
class Solution {
public:
    TreeNode *BST(vector<int> &num, int left, int right)
    {
        if(left>right)
        return NULL;
        int mid = (left+right)/2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = BST(num,left,mid-1);
        root->right = BST(num,mid+1,right);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = num.size();
        if(len==0)
        return NULL;
        return BST(num,0,len-1);
        
    }
};
