class Solution {
    vector<int>parent;
    vector<int>rank;
public:
    int findRoot(int node) //find + path compression
    {
        int nodeParent = parent[node];
        if(nodeParent == node)
        {
            return nodeParent;
        }
        parent[node] = findRoot(nodeParent);
        return parent[node];
    }

    void myUnion(int i , int j)
    {
        int di = findRoot(i);
        int dj = findRoot(j);
        if(rank[di] >= rank[dj])
        {
            rank[di] += rank[dj];
            parent[dj] = di;
        }
        else
        {
            rank[dj] += rank[di];
            parent[di] = dj;
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n); //rank by numbers of tree
        int component = n;
        for(int i = 0 ; i < n ; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
        for(vector<int>& edge : edges)
        {
            if(findRoot(edge[0]) != findRoot(edge[1]))
            {
                myUnion(edge[0],edge[1]);
                component--;
            }
        }
        return component;
    }
};
