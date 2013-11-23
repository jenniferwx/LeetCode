/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int max = INT_MIN;
        int len = prices.size();
        if(len<=0)
        return 0;
        
        vector<int> buy(len,0);
        vector<int> sell(len,0);
        buy[0] = prices[0];
        sell[len-1] = prices[len-1];
        for(int i=1;i<len;i++)
        {
            buy[i] = prices[i]<buy[i-1]?prices[i]:buy[i-1];
        }
        for(int i=len-2;i>=0;i--)
        {
            sell[i] = sell[i+1]>prices[i]?sell[i+1]:prices[i];
        }
        
        for(int i=0;i<len;i++)
        {
            if((sell[i]-buy[i])>max)
            max = sell[i]-buy[i];
        }
        return max;
    }
};
