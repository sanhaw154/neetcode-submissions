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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> timestamp;

        int maxTime = 0;
        for(Interval& interval : intervals)
        {
            timestamp[interval.start] += 1;
            timestamp[interval.end] -= 1;  
            maxTime = max(maxTime,interval.end);
        }
        int room = 0;
        int res = room;
        for(auto& [time,roomIncr] : timestamp)
        {
            room +=roomIncr;
            if(res < room) res = room;
        }
        return res;
    }
};
