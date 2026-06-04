class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<vector<int>> adj(n);
        for(vector<int>& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return isConnected(adj);
    }
    bool isConnected(vector<vector<int>>& adj)
    {
        int n = adj.size();
        vector<bool> visited(n,false);
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i]) 
            {
                dfs(adj,visited,i);
                break;
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i]) return false;
        }
        return true;
    }
    void dfs(vector<vector<int>>& adj,vector<bool>& visited,int node_num)
    {
        visited[node_num] = true;
        for(int& adjNode : adj[node_num])
        {
            if(!visited[adjNode]) dfs(adj,visited,adjNode);
        }
        return;
    }
};
