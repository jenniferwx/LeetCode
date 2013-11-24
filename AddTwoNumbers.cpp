/*
You are given two linked lists representing two non-negative numbers. The digits are stored in 
reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!l1)
        return l2;
        if(!l2)
        return l1;
        
        ListNode *L = new ListNode(0);
        ListNode *p = L;
        int carry = 0;
        while(l1 && l2)
        {
            int sum = (l1->val)+(l2->val)+carry;
            L->next = new ListNode(sum%10);
            carry = sum/10;
            L = L->next;
            l1 = l1->next; l2=l2->next;
        }
        while(l1)
        {
            int sum = (l1->val)+carry;
            L->next = new ListNode(sum%10);
            carry = sum/10;
            L = L->next;
            l1=l1->next;
        }
        while(l2)
        {
            int sum = (l2->val)+carry;
            L->next = new ListNode(sum%10);
            carry = sum/10;
            L = L->next;
            l2=l2->next;
        }
        if(carry)
        L->next = new ListNode(carry%10);
        
        return p->next;
    }
};
