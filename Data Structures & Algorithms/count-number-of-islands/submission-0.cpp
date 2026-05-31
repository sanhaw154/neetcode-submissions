class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<char>> visited(grid.size(),vector<char>(grid[0].size(),'0'));
        int count = 0 ;
        while(grid != visited)
        {
            for(int i = 0 ; i < grid.size() ; i++)
            {
                for(int j = 0 ; j < grid[0].size() ; j++)
                {
                    if(grid[i][j] == '1')
                    {
                        count++;
                        dfs(grid,i,j);
                    }
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        grid[i][j] = '0';
        if(i>0 && grid[i-1][j] == '1') dfs(grid,i-1,j);
        if(i<grid.size()-1 && grid[i+1][j] == '1') dfs(grid,i+1,j);
        if(j>0 && grid[i][j-1] == '1') dfs(grid,i,j-1);
        if(j<grid[0].size()-1 && grid[i][j+1] == '1') dfs(grid,i,j+1);
        return;
    }
};
