class Solution {
    vector<vector<int>> res;
    vector<int> per;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int& num : nums)
        {
            freq[num]++;
        }
        func(nums,freq);
        return res;
        
    }
    void func(vector<int>& nums,unordered_map<int,int>& freq)
    {
        if(per.size() == nums.size())
        {
            res.push_back(per);
        }
        for(auto [num,f] : freq)
        {
            if(!f) continue;
            per.push_back(num);
            freq[num]--;
            func(nums,freq);
            per.pop_back();
            freq[num]++;
        }
        return;
    }
};
