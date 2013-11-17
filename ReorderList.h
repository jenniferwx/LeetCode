/*
 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 

Written by Xi Wang
11/16/2013

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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head)
        return;
        ListNode *head2 = head;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast)
        {
            fast = fast->next;
            if(fast)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        //reverse the second half:
        ListNode *save = slow;
        ListNode *curr = slow->next;
        while(curr)
        {
            ListNode *next = curr->next;
            curr->next = slow;
            slow = curr;
            curr = next;
        }
        //Reorder the list;
        while(head2!=save&&head2)
        {
            ListNode *next = head2->next;
            ListNode *next2 = slow->next;
            head2->next = slow;
            slow->next = next;
            head2 = next;
            slow = next2;
        }
        head2->next = NULL;
    }
};
