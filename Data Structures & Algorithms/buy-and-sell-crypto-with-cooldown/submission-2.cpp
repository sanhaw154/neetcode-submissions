class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0;
        else if (n == 2) return max(prices[1]-prices[0],0);
        vector <vector<int>>differ(n,vector<int>(n,0));
        for(int len = 1 ; len <= n ; len++)
        {
            for(int i = 0 ; i < n ; i++)
            {
                int j = len + i - 1;
                if( j >= n) break;
                if(len == 1) differ[i][j] = 0;
                else
                {
                    differ[i][j] = prices[j]-prices[i];
                }
            }
        }
        vector<int> dp(n,0); //dp[i]表在 i day買 i~n-1的maxprofit
        vector<int> dp2(n,0); //dp2[i]表在 i day不買 i~n-1的maxprofit
        dp[n-1] = dp2[n-1] = 0;
        dp[n-2] = differ[n-2][n-1];
        dp[n-3] = max(differ[n-3][n-2],differ[n-3][n-1]);
        for(int i = n-2 ; i >= 0 ; i--)
        {
            dp2[i] = max(dp[i+1],dp2[i+1]);
            for(int k = i+1 ; k <= n-1 ; k++)
            {   
                if(k < n-2) dp[i] = max(dp[i],differ[i][k]+max(dp[k+2],dp2[k+2]));
                else dp[i] = max(dp[i],differ[i][k]);
            }
        }
        return max(dp[0],dp2[0]);
    }
};
