/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
        //return restore_1(s);
        return restore_2(s);
    }
    
    //SOLUTION 1: DFS
    vector<string>  restore_1(string s)
    {
        vector<string> result;
        string ip;
        restoreIpAddressRe(s, result, ip, 0, 0);
        return result;
    }
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
        ip.resize(origSize);
    }
    
    //SOLUTION 2: BFS
    bool isValid(const char *str, int len)
    {
        if(str[0]=='0')
        {
            if(len==1)
            return true;
            else
            return false;
        }
        int num=0;
        for(int i=0;i<len;i++)
        {
            num = num*10+ (int)(str[i]-'0');
            if(num>255)
            return false;
        }
        if(num<=255&&num>=1)
        return true;
        else
        return false;
    }
    vector<string> restore_2(string s)
    {
        const char* str = s.c_str(); // from string to char*
        vector<string> result;
        if(s.size()==0)
        return result;
        int len = s.size();
        for(int i=1;i<len;i++)
        {
            if(!isValid(str,i)) continue;
            for(int j=i+1;j<len;j++)
            {
                if(!isValid(str+i,j-i)) continue;
                for(int m = j+1;m<len;m++)
                {
                    if(!isValid(str+j,m-j)) continue;
                    if(isValid(str+m,len-m))
                    {
                        result.push_back(s.substr(0,i)+"."+s.substr(i,j-i)+"."+s.substr(j,m-j)+"."+s.substr(m));
                    }
                }
            }
        }
        return result;
    }
};
