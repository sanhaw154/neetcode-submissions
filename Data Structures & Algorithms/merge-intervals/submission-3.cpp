class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        
        for(int i = 0 ; i < intervals.size() ; i++)
        {
            if( res.empty() || intervals[i][0] > res.back()[1] )
            {
                res.push_back(intervals[i]);
            }
            else
            {
                res.back()[0] = min(intervals[i][0],res.back()[0]);
                res.back()[1] = max(intervals[i][1],res.back()[1]);
            }
        }
        return res;
    }
};
