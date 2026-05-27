class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums,0,target,path,res);
        return res;
    }
    void dfs(vector<int>& nums, int start, int remain, vector<int>& path,vector<vector<int>>& res)
    {

        if(remain == 0) res.push_back(path);
        if(remain > 0)
        {
            for(int i = start ; i < nums.size() ; i++)
            {
                path.push_back(nums[i]);
                dfs(nums,i,remain - nums[i],path,res);
            }
        }
        if(!path.empty())path.pop_back();
        return ;
    }
};
