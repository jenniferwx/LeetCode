/* Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

Written by Xi Wang
11/14/2013
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
     //solution 1: use extrac space
     map<int,int> mymap;
     for(int i=0;i<n;i++)
     {
         mymap[A[i]]++;
     }
     
     map<int,int>::iterator iter = mymap.begin();
     for(;iter!=mymap.end();iter++)
     {
         if(iter->second==1)
         return iter->first;
     }
    }
    
     int singleNumber_2(int A[], int n) {
     //solution2: no extra memory
     int ones = 0,twos=0,threes =0;
     for(int i=0;i<n;i++)
     {
         twos = twos | ones&A[i];
         ones = ones ^ A[i];
         threes = ~(ones&twos);
         ones = ones & threes;
         twos = twos & threes;
     }
     return ones;
    }
};
