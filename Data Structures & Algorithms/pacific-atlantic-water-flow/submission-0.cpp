class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacificGet (m,vector<bool>(n,false));
        vector<vector<bool>> atlanticGet (m,vector<bool>(n,false));
        queue<pair<int,int>> pQ;
        queue<pair<int,int>> aQ;
        
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(i == 0 || j == 0)
                {
                    pacificGet[i][j] = true;
                    pQ.push({i,j});
                }
                if(i == m-1 || j == n-1)
                {
                    atlanticGet[i][j] = true;
                    aQ.push({i,j});
                }
            }
        }

        bfs(heights,pQ,pacificGet);
        bfs(heights,aQ,atlanticGet);
        
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(pacificGet[i][j] && atlanticGet[i][j])
                {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& Q , vector<vector<bool>>& get)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<pair<int,int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!Q.empty())
        {
            int len = Q.size();
            for(int i = 0 ; i < len ; i++)
            {
                auto [row,col] = Q.front();
                Q.pop();

                for(auto [adjR,adjC] : direction)
                {
                    adjR += row;
                    adjC += col;

                    if(adjR >= 0 && adjR < m && adjC >= 0 && adjC < n 
                        && !get[adjR][adjC]
                        && heights[adjR][adjC] >= heights[row][col])
                        {
                            get[adjR][adjC] = true;
                            Q.push({adjR,adjC});
                        }
                }
            }
        }
        return;
    }
};
