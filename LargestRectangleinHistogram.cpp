/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram. 
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        return largestRectangleArea_1(height);
    }
    
    int largestRectangleArea_1(vector<int> &height)
    {
        int len = height.size();
        vector<int> left(len,0);
        vector<int> right(len,len-1);
        for(int i=1;i<len;i++)
        {
            if(height[i]>height[i-1])
            left[i] = i;
            else
            {
                int idx = i-1;
                while(height[i]<=height[idx]&&idx>=0)
                {
                    left[i] = left[idx];
                    idx = left[idx]-1;
                }
            }
        }
        for(int i=len-2;i>=0;i--)
        {
            if(height[i]>height[i+1])
            right[i] = i;
            else
            {
                int idx = i+1;
                while(height[i]<=height[idx]&&idx<len)
                {
                    right[i] = right[idx];
                    idx = right[idx]+1;
                }
            }
        }
        int result = 0;
        for(int i=0;i<len;i++)
        {
            int area = height[i]*(right[i]-left[i]+1);
            result = max(result,area);
        }
        return result;
    }
};
