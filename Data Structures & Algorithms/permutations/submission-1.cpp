class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums,0);
        return res;
    }
    void perm(vector<int>&nums, int index)
    {
        if(index == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i = index ; i < nums.size() ; i++)
        {
            swap(nums[index],nums[i]);
            perm(nums,index+1);
            swap(nums[index],nums[i]);
        }
        return;
    }
};
