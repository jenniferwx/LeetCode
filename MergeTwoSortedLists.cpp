/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together 
the nodes of the first two lists.

*/
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!l1)
        return l2;
        if(!l2)
        return l1;
        ListNode *L = new ListNode(0);
        ListNode *head = L;
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                L->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                L->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            L = L->next;
        }
        while(l1)
        {
            L->next = new ListNode(l1->val);
            l1 = l1->next;
            L = L->next;
        }
        while(l2)
        {
            L->next = new ListNode(l2->val);
            l2 = l2->next;
            L = L->next; // dont forget
        }
        return head->next;
        
    }
};
