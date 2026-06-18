class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList(n+1);
        for(vector<int>& edge : times)
        {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];

            adjList[start].push_back({end,weight});
        }
        vector<int> sp(n+1,1e9);
        sp[k] = 0;
        vector<bool> isoptimal(n+1,false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 1 ; i <= n ; i++)
        {
            pq.push({sp[i],i});
        } 
        while(!pq.empty())
        {
            auto [spl,index] = pq.top();
            pq.pop();
            if(isoptimal[index]) continue;
            isoptimal[index] =true;

            for(auto& [adj,weight] : adjList[index])
            {
                if( sp[adj] > sp[index] + weight )
                {
                    sp[adj] = sp[index] + weight;
                    pq.push({sp[adj],adj});
                }
            }
        }
        int res = -1;
        for(int i = 1 ; i <= n ; i++)
        {
            if(i == k) continue;
            if(sp[i] == 1e9 ) return -1;
            res = max(res,sp[i]);
        }
        return res;
    }
};
