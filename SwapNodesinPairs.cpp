/*
 Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, 
only nodes itself can be changed. 

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
    ListNode *swapPairs(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head || !head->next)
        return head;
        ListNode *phead = new ListNode(0);
        phead->next = head;
        ListNode *p = phead;
        ListNode *curr = head;
        while(curr && curr->next)
        {
            ListNode *N = curr->next;
            ListNode *next2 = N->next;
            phead->next = N;
            N->next = curr;
            curr->next = next2;
            phead = curr;
            curr = next2;
        }
        return p->next;
    }
};
