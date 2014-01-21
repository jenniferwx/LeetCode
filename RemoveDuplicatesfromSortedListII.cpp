/*
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the 
 original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3. 
*/

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head)
        return NULL;
        ListNode* phead = new ListNode(0);
        phead->next = head;
        ListNode *curr = head;
        ListNode *p2 = phead;
        int duplicate = INT_MAX;
        while(curr)
        {
            if(curr->next&&curr->next->val==curr->val||curr->val==duplicate)
            {
                duplicate = curr->val;
                phead->next = curr->next;
                delete curr;  // IMPORTANT!!
                curr = phead->next;
            }
            else
            {
                phead = curr;
                curr = curr->next;
            }
        }
        return p2->next;
    }
};
