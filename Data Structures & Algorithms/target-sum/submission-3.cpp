class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum  = accumulate(nums.begin(),nums.end(),0);
        if (target > sum || target < -sum) return 0;
        vector<vector<int>> dp(nums.size(),vector<int>(sum*2+1,0)); //target range : -sum <= t <= sum (共2*sum + 1)
        // 0 <= t + sum <= 2*sum
        dp[0][dpOffset(nums[0],sum)] += 1;
        dp[0][dpOffset(0-nums[0],sum)] += 1;
        for(int i = 1 ; i < nums.size() ; i++)
        {
            for(int j = 0 ; j <= 2*sum ; j++)
            {
                if(dp[i-1][j] > 0) //0~i-1可以產生出此 sum of j
                {
                    dp[i][j-nums[i]] += dp[i-1][j];
                    dp[i][j+nums[i]] += dp[i-1][j];
                }
            }
        }
        return dp[nums.size()-1][dpOffset(target,sum)];
    }

    int dpOffset(int input, int& offset) // -sum -> 0  , sum -> 2*sum
    {
        return input + offset;
    }
};
