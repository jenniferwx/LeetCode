/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 
*/

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head)
        return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=1;i<=n&&fast;i++)
        {
            fast = fast->next;
        }
        if(!fast)
        return head->next;
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
