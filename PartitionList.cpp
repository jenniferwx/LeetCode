/*
Given a linked list and a value x, partition it such that all nodes less than x come before 
nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5. 
*/

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(!head)
        return NULL;
        ListNode *L1 = new ListNode(0);
        ListNode *L2 = new ListNode(0);
        ListNode *p1=L1, *p2=L2;
        while(head)
        {
            if(head->val<x)
            {
                L1->next = new ListNode(head->val);
                L1 = L1->next;
            }
            else
            {
                L2->next = new ListNode(head->val);
                L2 = L2->next;
            }
            head = head->next;
        }
        L1->next = p2->next;
        return p1->next;
    }
};
