class Solution { //dp(bottom up)
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int curA = 0, curB = 0;
        int succA = nums[n-1];
        int succB = nums[n-1];
        for(int i = n-2 ; i >=0 ; i--)
        {
            curB = max(nums[i],nums[i]+succB);
            curA = max(succA,curB);
            succB = curB;
            succA = curA;
        }
        return curA;
    }
};
