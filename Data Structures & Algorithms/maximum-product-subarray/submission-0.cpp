class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> curMax(n); //令curMax[i]為以ith ele為end之MaxSum 有三種情況 
        //nums[i]=0 curMax[i] = 0, nums[i]>0 curMax[i] = curMax[i-1]*nums[i], nums[i]<0 curMax[i]=curmin[i-1]*nums[i](--得+) 
        vector<int> curmin(n);
        curMax[0] = curmin[0] = nums[0];

        int res = nums[0];
        for(int i = 1 ; i < n ; i++)
        {
            if(nums[i] == 0)
            {
                curMax[i] = curmin[i] = 0;  
            }
            else if(nums[i] > 0)
            {
                curMax[i] = max(curMax[i-1]*nums[i],nums[i]);
                curmin[i] = min(curmin[i-1]*nums[i],nums[i]);
            }
            else
            {
                curMax[i] = max(curmin[i-1]*nums[i],nums[i]);
                curmin[i] = min(curMax[i-1]*nums[i],nums[i]);
            }
            res = max(res,curMax[i]);
        } 
        return res;
    }
};
