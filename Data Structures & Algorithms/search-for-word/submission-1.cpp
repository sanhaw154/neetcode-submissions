class Solution {
    bool find = false;
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                backtrack(board,visited,i,j,0,word);
            }
        }
        return find;
    }
    void backtrack(vector<vector<char>>& board,vector<vector<bool>>& visited,int row,int col,int wordIdx,string word)
    {   
        visited[row][col] = true; 
        if(board[row][col] == word[wordIdx])  wordIdx++;
        else wordIdx = 0;
        if(wordIdx == word.size())
        {
            find = true;
            return;
        }
        else
        {
            if(row > 0 && !visited[row-1][col]) backtrack(board,visited,row - 1,col,wordIdx,word); //up
            if(row < board.size() - 1 && !visited[row+1][col]) backtrack(board,visited,row + 1,col,wordIdx,word); //down
            if(col > 0 && !visited[row][col-1]) backtrack(board,visited,row,col - 1,wordIdx,word); //left
            if(col < board[0].size() - 1 && !visited[row][col+1]) backtrack(board,visited,row,col+1,wordIdx,word); //right
            visited[row][col] = false;
        return;
        }
        
    }
};
 