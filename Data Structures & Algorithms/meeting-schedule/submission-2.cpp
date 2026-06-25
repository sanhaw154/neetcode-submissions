/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const Interval& a ,const Interval& b){
            return a.start < b.start;
        });
        int prevEnd = intervals[0].end; 
        for(int i = 1 ; i < intervals.size() ; i++)
        {
            int cur_start = intervals[i].start;
            int cur_end = intervals[i].end;

            if(cur_start < prevEnd) return false;
            else prevEnd = cur_end ;
        }
        return true;
    }
};
