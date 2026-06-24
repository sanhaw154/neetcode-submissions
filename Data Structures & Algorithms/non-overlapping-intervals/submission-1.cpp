class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1] < b[1];
        });

        vector<int> choose = {0};
        int prevEnd = intervals[0][1];
        for(int i = 0 ; i < intervals.size() ; i++)
        {
            if(intervals[i][0] >= prevEnd)
            {
                choose.push_back(i);
                prevEnd = intervals[i][1];
            }
            // < prevEnd 則不選擇 
        }
        return intervals.size() - choose.size();
    }
};
