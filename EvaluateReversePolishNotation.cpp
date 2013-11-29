/*
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/
class Solution {
public:
    int str2int(string str)
    {
    	bool negative = false;
    	int i=0;
    	while(str[i]==' ')
    		i++;
    	if(str[i]=='-')
    	{	
    		negative = true;
    		i++;
    	}
    	int result = 0;
    	for(;i<str.length();i++)
    		result = result*10+(str[i]-'0');
    	return negative?(-1)*result:result;
    
    }
    int evalRPN(vector<string> &tokens) {
        int len = tokens.size();
        if(len<=0)
        return 0;
        stack<int> result;
        for(int i=0;i<len;i++)
        {
            string str = tokens[i];
			if(str.compare("+")!=0&& str.compare("*")!=0 &&str.compare("/")!=0 &&str.compare("-")!=0)
            result.push(str2int(str));
            else
            {
			        	if(str.compare("+")==0) // pay attention to str.compare()
                {
                    int res = 0;
                    for(int j=0;j<2;j++)
                    {
                        int num = result.top();
                        result.pop();
                        res +=num;
                    }
                    result.push(res);
                }
                
                else if(str.compare("-")==0)
                {
                    int res = 0;
                    int num1 = result.top();
                    result.pop();
                    int num2 = result.top();
                    result.pop();
                    result.push(num2-num1);
                }
                
				        else if(str.compare("*")==0)
                {
                    int res = 1;
                    for(int j=0;j<2;j++)
                    {
                        int num = result.top();
                        result.pop();
                        res *=num;
                    }
                    result.push(res);
                }
                
                else if(str.compare("/")==0)
                {
                    int res = 0;
                    int num1 = result.top();
                    result.pop();
                    int num2 = result.top();
                    result.pop();
                    result.push(num2/num1);
                }
            }
        }
        return result.top();
    }
};
