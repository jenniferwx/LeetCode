/*
 Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity. 

written by Xi Wang
11/18/2013

*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = num.size();
        if(len<=1)
        return len;
        map<int,int> mymap;
        for(int i=0;i<len;i++)
        mymap[num[i]] = i;
        
        int start=0,longest=0;
        int j=0;
        vector<bool> visited(len,false);
        for(int i=0;i<len;i++)
        {
            if(visited[i])
            continue;
            int idx = num[i]-1;
            int len = 1;
            while(mymap.find(idx)!=mymap.end())
            {
                visited[mymap[idx]] = true;
                idx--;
                len++;
            }
            idx = num[i]+1;
            while(mymap.find(idx)!=mymap.end())
            {
                visited[mymap[idx]] = true;
                idx++;
                len++;
            }
            if(len>longest)
            longest = len;
        }
        return longest;
    }
};
