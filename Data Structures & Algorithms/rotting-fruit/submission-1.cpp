class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int,int>> rotten;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j =0 ; j < n ; j++)
            {
                if(grid[i][j] == 2 )
                {
                    rotten.push_back({i,j});
                }
            }
        }
        int time = bfs(grid,rotten);

        for(int i = 0 ; i < m ; i++)
        {
            for(int j =0 ; j < n ; j++)
            {
                if(grid[i][j] == 1)
                {
                   return -1;
                }
            }
        }
        return time;
    }
    int bfs(vector<vector<int>>& grid,vector<pair<int,int>>& rotten)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
        

        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        for(auto& [row,col] : rotten)
        {
            q.push({row,col});
        }
        int time = -1;
        while(!q.empty())
        {
            int qSize = q.size();
            for(int i = 0 ; i < qSize ; i++)
            {
                auto [r , c] = q.front();
                q.pop();
                if( r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0 || visited[r][c] ) continue;
                
                visited[r][c] = true;
                grid[r][c] = 2;
                for(auto& [dx, dy] : direction)
                {
                    q.push({r+dx,c+dy});
                }
            }
            time++;
        }
        if(time>0) return time - 1;
        return 0;
    }
};
