/*
 Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? 

Written by Xi Wang
11/15/2013
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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head)
        return false;
        ListNode *slow = head;
        ListNode *fast = head;
        if(fast->next)
        fast = fast->next->next;
        else
        return false;
        while(fast&&fast!=slow)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast)
            fast = fast->next;
            else
            break;
        }
        if(!fast)
        return false;
        else
        return true;
        
        
    }
};
