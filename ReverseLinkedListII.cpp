/*
 Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. 
*/
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head)
        return NULL;
        ListNode *curr=head;
        ListNode *phead= new ListNode(0);
        phead->next=head;
        ListNode *prev=phead;
        int i;
        for(i=1;i<m;i++)
        {
            prev=curr;
            curr=curr->next;
        }
        ListNode *pprev = prev;
        ListNode *pcurr = curr;
        while(i<=n)
        {
            ListNode *Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=Next;
            i++;
        }
        pprev->next = prev;
        pcurr->next = curr;
        return phead->next;
        
    }
};
