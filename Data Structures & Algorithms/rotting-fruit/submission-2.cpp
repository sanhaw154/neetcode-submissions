class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        vector<pair<int,int>> rotten;
        for(int i = 0 ; i < m ; i++) //O(m*n)
        {
            for(int j =0 ; j < n ; j++)
            {
                if(grid[i][j] == 1 )
                {
                    fresh++;
                }
                if(grid[i][j] == 2 )
                {
                    rotten.push_back({i,j});
                }
            }
        }
        int time = bfs(grid,rotten,fresh); //O(m*n)

        if (fresh) return -1;
        return time;
    }
    int bfs(vector<vector<int>>& grid,vector<pair<int,int>>& rotten,int& fresh)
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
        int time = 0;
        while(fresh>0 && !q.empty())
        {
            int qSize = q.size();
            for(int i = 0 ; i < qSize ; i++)
            {
                auto [r , c] = q.front();
                q.pop();
                
                visited[r][c] = true;
                
                for(auto [dx, dy] : direction)
                {
                    dx += r;
                    dy += c;
                    if( dx < 0 || dx >= m || dy < 0 || dy >= n || grid[dx][dy] == 0 || visited[dx][dy] ) continue;
                    if(grid[dx][dy] == 1)
                    {
                        grid[dx][dy] = 2;
                        fresh--;
                        q.push({dx,dy});
                    }
                    
                }
            }
            time++;
        }
        return time;
    }
};
