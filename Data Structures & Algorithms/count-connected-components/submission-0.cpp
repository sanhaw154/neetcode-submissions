class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int component = 0;
        vector<vector<int>> adjacency_list(n);
        vector<bool> visited(n,false);
        for(auto& edge : edges)
        {
            adjacency_list[edge[0]].push_back(edge[1]);
            adjacency_list[edge[1]].push_back(edge[0]);
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i])
            {
                dfs(adjacency_list,visited,i);
                component++;
            } 
        }
        return component;
    }
    void dfs(vector<vector<int>>& adjacency_list,vector<bool>& visited,int node_num)
    {
        visited[node_num] = true;
        for(int& adjNode : adjacency_list[node_num])
        {
            if(!visited[adjNode]) dfs(adjacency_list,visited,adjNode);
        }
        return;
    }
};
