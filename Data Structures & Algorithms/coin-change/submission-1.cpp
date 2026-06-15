class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        for(int i = 1 ; i <= amount ; i++)
        {
            int min_count = INT_MAX;
            for(int& coin : coins)
            {
                if(coin > i || dp[i-coin] < 0 ) continue;
                else 
                {
                    min_count = min(min_count,dp[i-coin]);
                }
            }
            if(min_count != INT_MAX) dp[i] = min_count + 1;
        }
        return dp[amount];
    }
};
