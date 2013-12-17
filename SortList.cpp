/*
Sort a linked list in O(n log n) time using constant space complexity.
*/

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return BinarySort(head);
    }
    ListNode *BinarySort(ListNode *head)
    {
        if(!head||!head->next)
        return head;
        ListNode *p = head, *prev= head;
        ListNode *q = head;
        while(q&&q->next)
        {
            q = q->next->next;
            prev = p;
            p = p->next;
        }
        prev->next = NULL;
        ListNode *L1 = BinarySort(head);
        ListNode *L2 = BinarySort(p);
        return Sort(L1,L2);
    }
    ListNode *Sort(ListNode *L1, ListNode *L2)
    {
        if(!L1&&!L2)
        return NULL;
        ListNode *res = new ListNode(0);
        ListNode *phead = res;
        while(L1&&L2)
        {
            if(L1->val<L2->val)
            {
                res->next = L1;
                L1 = L1->next;
            }
            else
            {
                res->next = L2;
                L2 = L2->next;
            }
            res = res->next;
        }
        if(L1)
            res->next = L1;
        else
            res->next = L2;

        return phead->next;
    }
};
