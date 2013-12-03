/*
 Given two words word1 and word2, find the minimum number of steps required to convert 
 word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        //return Distance_1(word1,word2);
        return Distance_2(word1,word2);
    }
    
    // SOLUTION 1: time complexity O(mn), space complexity O(mn)
    int Distance_1(string word1,string word2)
    {
        int len1 = word1.size();
        int len2 = word2.size();
        int dist[len1+1][len2+1]; // pay attention to the size of the matrix
        dist[0][0] = 0;
        
        for(int i=1;i<=len1;i++)
        dist[i][0] = i;
        for(int i=1;i<=len2;i++)
        dist[0][i] = i;
        
        for(int i=1;i<=len1;i++)
        for(int j=1;j<=len2;j++)
        {
            if(word1[i-1]==word2[j-1])
            dist[i][j] = dist[i-1][j-1];
            else
            dist[i][j] = min(dist[i-1][j-1], min(dist[i-1][j],dist[i][j-1]))+1;
        }
        return dist[len1][len2];
    }
    
    // SOLUTION 2: time complexity O(mn), space complexity O(n)
    int Distance_2(string word1,string word2)
    {
        int len1 = word1.size();
        int len2 = word2.size();
        int dist[len2+1]; 
        for(int j=0;j<=len2;j++)
        dist[j] = j;
        
        for(int i=1;i<=len1;i++)
        {
            int upperleftprev = dist[0]; // the value of the upperleft entry in the matrix
            dist[0] = i;
            for(int j=1;j<=len2;j++)
            {
                int upperleft = upperleftprev;
                upperleftprev = dist[j]; //restore the the value for the upperleft entry
                
                if(word1[i-1]==word2[j-1])
                dist[j] = upperleft;
                else
                dist[j] = min(upperleft, min(dist[j-1],dist[j])) + 1;
            }
        }
        return dist[len2];
    }
};
