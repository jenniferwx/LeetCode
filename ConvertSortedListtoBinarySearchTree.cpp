/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode *BST(ListNode *head, ListNode *end)
    {
        if(!head || head==end)
        return NULL;
        // find the middle node in the current list
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=end)
        {
            fast = fast->next;
            if(fast!=end)
            {
                fast = fast->next;
                slow = slow->next;
            }
            else
            break;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = BST(head,slow);
        root->right = BST(slow->next,end);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
     TreeNode *root = BST(head,NULL);
     return root;
    }
};
