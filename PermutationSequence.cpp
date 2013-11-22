/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

Written by Xi Wang
11/21/2013

*/

class Solution {
public:
    string getPermutation(int n, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int total = 1;
        string num,result;
        for(int i=1;i<=n;i++)
        {
            num.push_back(i+'0');
            total = total*i;
        }
        k--;
        while(n)
        {
            total = total/n;
            int i = k/total;
            k = k%total;
            result.push_back(num[i]);
            num.erase(i,1);
            n--;
        }
        return result;
        
    }
};
