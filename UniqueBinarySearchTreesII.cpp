/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path 
terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".

Written by Xi Wang
11/19/2013

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
    vector<TreeNode *> generateSubTrees(int l, int r)
    {
        vector<TreeNode*> res;
        if (l > r) {
            res.push_back(NULL);
            return res;
        }
        for (int k = l; k <= r; k++) {
            vector<TreeNode*> leftTrees = generateSubTrees(l, k-1);
            vector<TreeNode*> rightTrees = generateSubTrees(k+1, r);
            for (size_t i = 0; i < leftTrees.size(); i++) {
                for (size_t j = 0; j < rightTrees.size(); j++) {
                    TreeNode* root = new TreeNode(k);
                    root->left = leftTrees[i];
                    root->right = rightTrees[j];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode *> generateTrees(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return generateSubTrees(1,n);
    }
};
