struct cmp {
    bool operator()(const pair<int,int>& a,
                    const pair<int,int>& b) const {
        return a.second > b.second;
    }
};
class Solution {
    int manhattan(int i ,int j ,vector<vector<int>>& points)
    {
        return abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int v = points.size();
        int start = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        for(int i = 0 ; i < v ; i++)
        {
            if(i != start)pq.push({i,manhattan(start,i,points)});
        }
        int mstCost = 0;
        unordered_set<int> mst;
        unordered_set<int> unjoin;
        for(int i = 0 ; i < v ; i++)
        {
            if(i != start)unjoin.insert(i);
        }
        mst.insert(start);
        while(!unjoin.empty())
        {
            auto [nextchoose,weight] = pq.top();
            pq.pop();
            if(!mst.count(nextchoose))
            {
                unjoin.erase(nextchoose);
                mst.insert(nextchoose);
                for(int unjoinNode : unjoin)
                {
                    pq.push({unjoinNode,manhattan(nextchoose,unjoinNode,points)});
                }
                mstCost += weight;
            }
        }
        return mstCost;
    }
};
