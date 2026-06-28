class Solution {
    vector<vector<int>> memo;
    vector<vector<bool>> find;
public:
    int change(int amount, vector<int>& coins) {
        memo.assign(amount+1,vector<int>(coins.size(),0));
        find.assign(amount+1,vector<bool>(coins.size(),false));
        return dfs(amount,0,coins);
    }
    int dfs(int target ,int cur_coin, vector<int>& coins)
    {
        if(target==0) return 1;
        if(find[target][cur_coin]) return memo[target][cur_coin];
        int combination = 0;
        for(int i = cur_coin ; i < coins.size() ; i++)
        {
            if( coins[i] <= target) combination += dfs(target - coins[i] ,i, coins); 
        }
        memo[target][cur_coin] = combination;
        find[target][cur_coin] = true;
        return combination;
    }
};
