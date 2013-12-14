/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18]. 
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool compare(Interval a, Interval b)
{
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        int len = intervals.size();
        if(len<=1)
        return intervals;
        sort(intervals.begin(), intervals.end(), compare);
        Interval Last = intervals[0];
        for(int i=1;i<len;i++)
        {
            if(intervals[i].start<=Last.end)
            Last.end = max(Last.end, intervals[i].end);
            else
            {
                res.push_back(Last);
                Last = intervals[i];
            }
        }
        res.push_back(Last);
        return res;
    }
};
