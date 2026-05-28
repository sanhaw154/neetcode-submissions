class Solution {
    vector<vector<int>> res;
    vector<int> path;
    string pathStr;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sortedEle = candidates;
        sort(sortedEle.begin(),sortedEle.end());
        dfs(sortedEle,0,target);
        return res;

    }
    void dfs(vector<int>& nums ,int start, int remain)
    {
        if(remain == 0)
        {
            res.push_back(path);
        }
        else if (remain > 0)
        {
            for( int i = start ; i < nums.size() ; i++)
            {
                if(i > start && nums[i] == nums[i-1]) continue;
                path.push_back(nums[i]);
                dfs(nums,i + 1,remain - nums[i]);
                path.pop_back();
            }
        }
        return;
    }
};
