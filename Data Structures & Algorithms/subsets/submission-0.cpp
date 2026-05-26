class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int index = 0;
        vector<vector<int>> res = {};
        vector<int> subset = {};
        subsetsFind(nums,index,subset,res);
        return res;
    }
    void subsetsFind(vector<int>& nums,int index,vector<int> subset,vector<vector<int>>& res)
    {
        if (index == nums.size()) 
        {
            res.push_back(subset);
            return;
        }
        subsetsFind(nums,index + 1,subset,res);

        subset.push_back(nums[index]);
        subsetsFind(nums,index + 1,subset,res);

        return;
    }
};
