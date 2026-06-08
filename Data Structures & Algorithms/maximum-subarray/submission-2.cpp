class Solution { //recursion + memorize
    int res = INT_MIN;
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<array<int,2>>memo(n); // suffixSum when flag == true and flag == false
        vector<array<int,2>>seen(n,{false,false});
        
        return dfs(nums,0,false,memo,seen);
    }
    int dfs(vector<int>& nums, int i , bool flag,vector<array<int,2>>& memo , vector<array<int,2>>& seen) //return i~n-1th maxSum
    {   
        if(i == nums.size() - 1 ) return flag ? max(0,nums[i]) : nums[i]; //if flag is true, the last element dont have to choose. 0 means no element behind index i.
        int f = flag ? 1 : 0 ;
        if(seen[i][f]) return memo[i][f];
        if(flag)
        {
            memo[i][f] = max( dfs(nums,i+1,true,memo,seen) + nums[i] ,0); // 繼續往下or在此停下（不含nums[i])
        }
        else
        {
            memo[i][f] = max( dfs(nums,i+1,false,memo,seen) , nums[i] + dfs(nums,i+1,true,memo,seen) ); //不在此開始 or 在此開始（含i）
        }

        seen[i][f] = true;
        return memo[i][f];
    }
};
