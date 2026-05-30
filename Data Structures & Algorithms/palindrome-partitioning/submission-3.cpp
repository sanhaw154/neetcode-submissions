class Solution {
    vector<vector<string>> res;
    vector<string> split;
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int l = 0; l < n; l++) {
            for (int i = 0; i + l < n; i++) {
                int j = i + l;

                if (i == j) {
                    dp[i][j] = true;
                }
                else if (i + 1 == j) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
            }
        }
        dfs(s,0,dp);
        return res;
    }
    void dfs(string& s,int start,vector<vector<bool>>& dp)
        {
            if(start == s.size())
            {
                res.push_back(split);
                return;
            }

            for(int end = start ; end < s.size() ; end++)
            {
                if(dp[start][end])
                {
                    split.push_back(s.substr(start,end-start+1));
                    dfs(s,end+1,dp);
                    split.pop_back();
                }
            }
            return;
        }
};
