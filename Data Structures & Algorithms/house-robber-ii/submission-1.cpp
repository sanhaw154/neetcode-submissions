class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        if (n==2) return max(nums[0],nums[1]);
        vector<int> cho0(n);
        vector<int> notcho0(n);
        cho0[0] = nums[0];
        notcho0[0] = 0;
        cho0[1] = cho0[0];
        notcho0[1] = nums[1];
        for(int i = 2 ; i < n-1 ; i++)
        {
             cho0[i] = max(nums[i] + cho0[i-2],cho0[i-1]);
             notcho0[i] = max(nums[i] + notcho0[i-2],notcho0[i-1]);
        }
        cho0[n-1] = cho0[n-2];
        notcho0[n-1] = max(nums[n-1] + notcho0[n-3],notcho0[n-2]);
        return max(cho0[n-1],notcho0[n-1]);
    }
};
