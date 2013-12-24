/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string. */
class Solution {
public:

    string countAndSay(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        string result="1";
       while(--n>0){
           string next;
           char last=result[0];
           int count=1;
           for(int i=1;i<result.length();++i){
               if(result[i]!=last){
                   next.push_back(count+'0');
                   next.push_back(last);
                   last=result[i];
                   count=1;
               }else{
                   ++count;
               }
           }
           if(count){
               next.push_back(count+'0');
               next.push_back(last);
           }
           result=next;
       }
       return result; 
    }
};
