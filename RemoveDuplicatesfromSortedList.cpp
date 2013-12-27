/*
 Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. 

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head)
        return NULL;
        ListNode *phead = new ListNode(head->val);
        ListNode *pphead = phead;
        head = head->next;
        while(head)
        {
            if(head->val != phead->val&& head)
            {
                phead->next = new ListNode(head->val);
                phead = phead->next;
            }
            head = head->next;
        }
        return pphead;
    }
};
