/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    #define PI 3.14159265
    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //Solution1:
        int size = points.size();
        if(size<=2)
        return size;
        int maxPoints = 0;
        for(int i = 0; i < size-1;i++)
        {
        	map<double,set<int>> mymap;
		int duplicates = 0;
		for(int j = ; j < size; j++)
		{
		  if(points[i].x==points[j].x && points[i].y == points[j].y && i!=j)
		{
		  duplicates++; 
		  continue;
		} // record the number of duplicate points
		
		double diffy = points[i].y-points[j].y;
		double diffx = points[i].x-points[j].x;
		double slope;
		if(diffx==0)
	          slope = PI/2;
		else if(diffy==0)
		  slope = 0;
		else
		  slope = atan(diffy/diffx);
		mymap[slope].insert(i);
		mymap[slope].insert(j);
		}
    	    map<double,set<int>>::iterator iter = mymap.begin();
            while(iter!=mymap.end())
            {
    		set<int> res = iter->second;
                if(res.size()+duplicates>maxPoints)
                   maxPoints = res.size()+duplicates;
                iter++;
            }
	}

        return maxPoints;
    }
};
