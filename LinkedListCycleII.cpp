/*
 Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space? 

Written by Xi Wang
11/15/2013

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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head)
        return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            break;
        }
        if(!fast ||!fast->next)
        return NULL;
        // find the start of the cycle begin
        fast = head;
        while(fast!=slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
