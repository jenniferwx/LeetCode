/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
*/
class Solution {
public:
    ListNode* Merge(ListNode *a, ListNode *b)
    {
        if(!a&&!b) return NULL;
        if(!a) return b;
        if(!b) return a;
        ListNode *c = new ListNode(0);
        ListNode *phead = c;  
        while(a||b)
        {
            if(a&&b)
            {
                if(a->val<=b->val)
                {
                    c->next = new ListNode(a->val);
                    a = a->next;
                }
                else
                {
                    c->next = new ListNode(b->val);
                    b = b->next;
                }
            }
            else if(a)
            {
                c->next = new ListNode(a->val);
                a = a->next;
            }
            else if(b)
            {
                c->next = new ListNode(b->val);
                b = b->next;
            }
            c = c->next;
        }
        return phead->next;
    }
    ListNode* mergeK(vector<ListNode *> &Lists, int start, int end)
    {
        if(end<start) return NULL;
        if(start==end) return Lists[start];
        if(end-start==1) return Merge(Lists[start],Lists[end]);// THis is important!!!
        int mid = (start+end)/2;
        ListNode *a = mergeK(Lists,start,mid);
        ListNode *b = mergeK(Lists,mid+1,end);
        return Merge(a,b);
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int len = lists.size();
        return mergeK(lists,0,len-1);
    }
};
