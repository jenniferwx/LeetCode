/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> result;
        string ip;
        restoreIpAddressRe(s, result, ip, 0, 0);
        return result;
    }
    //SOLUTION 1: DFS
    void restoreIpAddressRe(string s, vector<string> &result, string &ip, int start, int deep)
    {
        if(deep==4 && start == s.size())
        {
            result.push_back(ip);
        }
        if(deep==4)
        return;
        
        int num = 0, origSize = ip.size();
        if(origSize!=0) ip.push_back('.');
        for(int i=start;i<s.size();i++)
        {
            num = num*10+(s[i]-'0');
            if(num>255) break;
            ip.push_back(s[i]);
            restoreIpAddressRe(s,result,ip,i+1,deep+1);
            if(num==0) break;
        }
        ip.resize(origSize); // resize (cut) the IP address to the previous size
    }
};
