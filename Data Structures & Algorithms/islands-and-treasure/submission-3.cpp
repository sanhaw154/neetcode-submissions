class Solution {
    const int INF = 2147483647;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();


        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == INF)
                {
                    vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
                    grid[i][j] = bfs(grid,i,j,visited);
                }   
            }
        }
    }
    int bfs (vector<vector<int>>& grid,int i , int j,vector<vector<int>>& visited)
    {   
        int m = grid.size();
        int n = grid[0].size();

        int minDis = INF;
        int level = -1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty())
        {
            level++;
            int s = q.size();
            for(int i = 0 ; i < s ; i++)
            {
                auto [ row , col ] = q.front();
                q.pop();
                if(row<0 || row>=m || col<0 || col>=n || grid[row][col] == -1 || visited[row][col] == 1) continue;
                if(grid[row][col] == 0)
                {
                    return level;
                }
                visited[row][col] = 1;
                q.push({row+1,col});
                q.push({row-1,col});
                q.push({row,col+1});
                q.push({row,col-1});
            }
        }
        return minDis;
    }
};
