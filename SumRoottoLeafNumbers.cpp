/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25. 
*/

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum=0,sub=0;
        subsum(root,sum,sub);
        return sum;
    }
    void subsum(TreeNode *root,int &result,int &sub)
    {
        if(root==NULL)
        return;
        sub =sub*10+root->val;
        if(!root->left && !root->right)
        {
            result +=sub;
        }
        subsum(root->left,result,sub);
        subsum(root->right,result,sub);
        sub = sub/10;
    }
};
