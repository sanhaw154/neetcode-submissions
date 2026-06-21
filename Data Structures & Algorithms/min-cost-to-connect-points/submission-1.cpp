class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();
        vector<vector<int>> dist(v,vector<int>(v,0));
        for(int i = 0 ; i < v ; i++)
        {
            for(int j = 0 ; j < v ; j++)
            {
                dist[i][j] = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
            }
        }
        int mstCost = 0;
        unordered_set<int> mst;
        mst.insert(0);
        while(mst.size()<v)
        {
            int minWeight = 4e6+1;
            int nextchoose = 0;
            for(int node : mst)
            {
                for(int i = 0 ; i < v ; i++)
                {
                    if(mst.count(i))continue;
                    if(minWeight > dist[node][i])
                    {
                        minWeight = dist[node][i];
                        nextchoose = i;
                    }
                }
            }
            mst.insert(nextchoose);
            mstCost += minWeight;
        }
        return mstCost;
    }
};
