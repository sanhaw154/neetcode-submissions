class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            return a[0] < b[0];
        });

        int res = 1;
        int prevEnd = intervals[0][1];
        for(int i = 0 ; i < intervals.size() ; i++)
        {

            if(intervals[i][0] < prevEnd)
            {
                prevEnd = min(prevEnd,intervals[i][1]);
            }
            else 
            {
                res += 1;
                prevEnd = intervals[i][1];
            }
        }
        return intervals.size() - res;
    }
};
