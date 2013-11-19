/*
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 

written by Xi Wang
11/19/2013


*/

**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
                if(!head)
        return NULL;
        ListNode *phead = new ListNode(0);
        phead->next = head;
        ListNode *pphead = phead;
        if(k<=1)
        return head;
        
        while(head)
        {
            int N = k;
            ListNode *begin = head;
            ListNode *end = head;
            while(N>1 && end)
            {
                end = end->next;
                N--;
            }
            if(!end)
            break;

            ListNode *curr = begin->next;
            while(N<k)
            {
                ListNode *next = curr->next;
                curr->next = begin;
                begin = curr;
                curr = next;
                N++;
            }
            phead->next->next = curr;
            ListNode *t1 = phead->next;
            phead->next = begin;
            phead = t1;
			head = curr;
        }
        return pphead->next;
    }
};
