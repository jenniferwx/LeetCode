/*
 Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 

*/
class Solution {
public:
    string addBinary(string a, string b) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len1 = a.size();
        int len2 = b.size();
        int carry = 0;
        string result="";
        int i,j;
        for(i=len1-1,j=len2-1;i>=0||j>=0;i--,j--)
        {
            int num = carry;
            if(i>=0) num = num + (a[i]-'0');
            if(j>=0) num = num + (b[j]-'0');
            result += (num%2)+'0';
            carry = num/2;
        }
        if(carry==1)
        result += carry +'0';
        int len = result.size();
        i=0;
        while(i<len/2)
        {
            swap(result[i],result[len-1-i]); //reverse the string, better solution is shown below
            i++;
        }
        return result;
    }
    
    // More simpler solution
    string addBinary(string a, string b) {
        int len1 = a.size();
        int len2 = b.size();
        int carry = 0;
        string result="";
        int i,j;
        for(i=len1-1,j=len2-1;i>=0||j>=0;i--,j--)
        {
            int num = carry;
            if(i>=0) num = num + (a[i]-'0');
            if(j>=0) num = num + (b[j]-'0');
            result.insert(result.begin(), (num%2)+'0');
            carry = num/2;
        }
        if(carry==1)
        result.insert(result.begin(),carry+'0');
        return result;
    }
