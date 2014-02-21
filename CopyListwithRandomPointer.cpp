/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
        return NULL;
        unordered_map<RandomListNode*,RandomListNode*> map;
        RandomListNode dummy(0),*CurrNew=&dummy,*cur = head;
        while(cur)
        {
            if(map.find(cur)==map.end())
            map[cur] = new RandomListNode(cur->label);
            if(cur->random &&map.find(cur->random)==map.end())
            map[cur->random] = new RandomListNode(cur->random->label);
            CurrNew->next = map[cur];
            CurrNew = CurrNew->next;
            CurrNew->random = map[cur->random];
            cur = cur->next;
        }
        return dummy.next;
    }
};
