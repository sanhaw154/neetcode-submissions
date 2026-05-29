class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0] = {""};
        for(int l = 1 ; l <= n ; l++)
        {
            for( int k = 0 ; k < l ; k++)
            {
                for(string& left : dp[k])
                {
                    for(string& right : dp[l-k-1])
                    {
                        string cur = '(' + left +')' + right ;
                        dp[l].push_back(cur);
                    }
                }
            }
        }
        return dp[n];
    }
    
};
