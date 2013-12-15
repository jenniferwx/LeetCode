/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
*/

class Solution {
public:
    string convert(string s, int nRows) {
       if(nRows==1)
       return s;
       vector<vector<char>> V(nRows, vector<char>());
       int isZ=0,k=0;
       for(int i=0;i<s.size();i++)
       {
           V[k].push_back(s[i]);
           if(isZ==0)// not in the Z position
           {
               if(k+1==nRows)
               {
                   k--;
                   isZ=1;
               }
               else
               k++;
           }
           else
           {
               if(k==0)
               {
                   k++;
                   isZ=0;
               }
               else
               k--;
           }
       }
       string result ="";
       for(int i=0;i<nRows;i++)
       for(int j=0;j<V[i].size();j++)
           result+=V[i][j];
           
       return result;
    }
    
    // Solution2
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        string res;
        int inc = (nRows - 1) * 2, N = s.size();
        for (int i = 0; i < nRows; ++i)
        {
            int j = 0;
            while (true)
            {
                if (i > 0 && i < nRows-1 && j-i >= 0 && j-i < N)
                    res.push_back(s[j-i]);
                if (j+i < N)
                    res.push_back(s[j+i]);
                if (j+i >= N)
                    break;
                j += inc;
            }
        }
        return res;
    }
};
