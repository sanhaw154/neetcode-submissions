class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool isInsert = false;
        for(int i = 0 ; i < intervals.size() ; i++)
        {
            if(intervals[i][1] < newInterval[0]) //ei < st
            {
                res.push_back(intervals[i]);
            }
            else if(newInterval[1] < intervals[i][0]) // et < si
            {
                if(!isInsert)
                {
                    isInsert = true;
                    res.push_back(newInterval);
                }
                res.push_back(intervals[i]);
            }
            else 
            {
                newInterval[0] = min(newInterval[0],intervals[i][0]);
                newInterval[1] = max(newInterval[1],intervals[i][1]);
            }
        }
        if(!isInsert) res.push_back(newInterval);
        return res;

    }
};
