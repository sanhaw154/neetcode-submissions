class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = subsetsFind(nums,0);
        return res;
    }
    vector<vector<int>> subsetsFind(vector<int>& nums,int index) 
    { 
        vector<vector<int>> res;
        if (index == nums.size()) 
        {
            res.push_back({}); 
            return res ; 
        } 

        vector<vector<int>> backsubset = subsetsFind(nums,index + 1);
        

        for(auto subset : backsubset) //共有2^(n-i-1)個subset i : index
        {
            vector<int> have = subset;
            have.push_back(nums[index]);
            res.push_back(have);

            vector<int> dontHave = subset;
            res.push_back(dontHave);
        }
        return res;
    }
};