class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<tuple<int,int,int>>maxHeap;
        vector<tuple<int,int,int>> record;
        for(int i = 0 ; i < points.size() ; i++ )
        {
            int disSqu = (points[i][0])*(points[i][0]) + (points[i][1])*(points[i][1]);
            
            maxHeap.push({disSqu,points[i][0],points[i][1]});
            if(maxHeap.size()>k)
            {
                maxHeap.pop();
            }
        }
        while(!maxHeap.empty())
        {
            auto [dis,x,y] = maxHeap.top();
            maxHeap.pop();
            res.push_back({x,y});
        }
        return res;
    }
};
