class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int l = 0;
        int r = intervals.size()-1;
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(intervals[mid][1] < newInterval[0] )
            {
                l = mid + 1; 
            }
            else if (intervals[mid][1] >= newInterval[0] )
            {
                r = mid - 1;
            }
        }
        int mergedLeft = l;
        int mergedRight = mergedLeft;
        while( mergedRight < intervals.size() && intervals[mergedRight][0] <= newInterval[1] )
        {
            mergedRight++;
        }
        mergedRight = mergedRight - 1;

        // return {{mergedLeft,mergedRight}};
        for(int i = mergedLeft ; i <= mergedRight ; i++)
        {
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
        }
        for(int i = 0 ; i < mergedLeft ; i++)
        {
            res.push_back(intervals[i]);
        }
        res.push_back(newInterval);
        for(int i = mergedRight+1 ; i < intervals.size() ; i++)
        {
            res.push_back(intervals[i]);
        }
        return res;
    }
};
