/*
Sort a linked list using insertion sort.
Written by Xi Wang
11/13/2013
*/

/* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head)
        return NULL;
        ListNode *phead = new ListNode(0);
        phead->next = new ListNode(head->val);
        ListNode *p = phead;
        head = head->next;
        while(head)
        {
            ListNode *curr = phead->next;
            if(head->val<=phead->next->val){
                ListNode *n = new ListNode(head->val);
                n->next = phead->next;
                phead->next = n;
            }
            
            else
            {
                while(curr->next && head->val>curr->next->val)
                {
                    curr = curr->next;
                }
                ListNode *next = curr->next;
                curr->next = new ListNode(head->val);
                curr = curr->next;
                curr->next = next;
            }
            head = head->next;
        }
        return p->next;
    }
};
