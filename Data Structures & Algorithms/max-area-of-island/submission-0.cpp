class Solution {
    int max_node = 0;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == 1)
                {
                    int node_num = 0;
                    dfs(grid,i,j,node_num);
                    if(max_node < node_num) max_node = node_num;
                }
            }
        }
        return max_node;
    }
    void dfs(vector<vector<int>>& grid, int i ,int j,int& num)
    {
        int m = grid.size();
        int n = grid[0].size();

        if(i<0 || i >=m || j<0 || j>=n ) return;
        if(grid[i][j] == 0) return;

        num++;
        grid[i][j] = 0 ;
        
        dfs(grid,i-1,j,num);
        dfs(grid,i+1,j,num);
        dfs(grid,i,j-1,num);
        dfs(grid,i,j+1,num);
        return;
    }
};
