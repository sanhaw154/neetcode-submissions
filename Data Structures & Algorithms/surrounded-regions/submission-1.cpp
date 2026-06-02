class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(board[i][j] == 'O' && !visited[i][j])
                {
                    bfs(board,{i,j},visited);
                }
            }
        }
        return;
    }
    void bfs(vector<vector<char>>& board,pair<int,int> start,vector<vector<bool>>& visited)
    {
        int m = board.size();
        int n = board[0].size();
        vector<pair<int,int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
        bool surrounded = true;
        vector<pair<int,int>>visitedPoint;
        queue<pair<int,int>> Q;

        Q.push(start);
        while(!Q.empty())
        {
            int len = Q.size();
            for(int i = 0 ; i < len ; i++)
            {
                auto [row,col] = Q.front();
                visitedPoint.push_back({row,col});
                Q.pop();
                visited[row][col] = true;
                for( auto [adjR,adjC] : direction )
                {
                    adjR += row;
                    adjC += col;

                    if(adjR <0 || adjR >= m || adjC < 0 || adjC >= n)
                    {
                        surrounded =false;
                        continue;
                    }
                    if(!visited[adjR][adjC] && board[adjR][adjC] == 'O') Q.push({adjR,adjC});
                }
            }
        }
        if(surrounded)
        {
            for( auto [row,col] : visitedPoint )
            {
                board[row][col] = 'X';
            }
            return;
        }
    }
};
