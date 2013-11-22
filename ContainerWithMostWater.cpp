/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at 
coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i 
is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, 
such that the container contains the most water.

Note: You may not slant the container. 

Written by Xi Wang
*/

class Solution {
public:
    int maxArea(vector<int> &height) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int MaxArea = INT_MIN;
        int len = height.size();
        int i=0,j=len-1;
        while(i<j)
        {
            int area = (j-i)*min(height[i],height[j]);
            if(area>MaxArea)
            MaxArea = area;
            if(height[i]<height[j])
            i++;
            else
            j--;
        }
        return MaxArea;
    }
};
