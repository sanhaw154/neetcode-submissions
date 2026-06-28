class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp (amount+1,vector<int>(coins.size()+1,0)); 
        // dp[i][j] represents the number of combinations to make amount i
        // using coins from index j to coins.size() -1.
        for(int i = 0 ; i <= amount ; i++)
        {   
            
            for(int j = coins.size()-1 ; j >= 0 ; j--)
            {   
                if(i == 0) //只要不選就是有
                {
                    dp[i][j] = 1;
                    continue;
                }
                if(coins[j] > i) dp[i][j] = 0;
                else if (coins[j] == i) dp[i][j] = 1;
                else 
                {   
                        dp[i][j] = dp[i-coins[j]][j] + dp[i][j+1]; //coins[j] < i //dp[i-coins[j]][j] 表以coins[j]為頭時 能有的組合數
                        // 再加上不含coins[j] j+1~n-1所能湊成amount of i 的組合數  
                    
                }
            }
        }
        return dp[amount][0];
    }
};
