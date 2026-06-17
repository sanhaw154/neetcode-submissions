class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2,vector<int>(n+2,0)); //dp[buying][day]

        for(int i = n-1 ; i >= 0 ; i--)
        {
            dp[0][i] = max(dp[0][i+1],dp[1][i+2] + prices[i]); //sell的選擇
            dp[1][i] = max(dp[1][i+1],dp[0][i+1] - prices[i]);
        }
        return dp[1][0];
    }
};
