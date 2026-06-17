class Solution {
    vector<vector<int>>memo;
public:
    int maxProfit(vector<int>& prices) {
        memo.assign(2,vector<int>(prices.size(),-1));
        return dfs(prices,0,true);
    }
    int dfs(vector<int>& prices,int day ,bool buying) //表從day開始的最大profit
    {
        if(day >= prices.size())return 0;
        if(memo[(int)buying][day] != -1) return memo[(int)buying][day];
        int cooldown = dfs(prices,day+1,buying);
        if(buying)
        {
            int buy = dfs(prices,day+1,false) - prices[day];
            memo[1][day] = max(buy,cooldown);
            return memo[1][day];
        }
        else
        {
            int sell = dfs(prices,day+2,true) + prices[day];
            memo[0][day] = max(sell,cooldown);
            return memo[0][day];
        }
    }
};
