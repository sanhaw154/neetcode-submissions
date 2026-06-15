class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> curMax(n); //令curMax[i] curmin[i]為以ith ele為end之MaxSum、minSum
        vector<int> curmin(n); //curMax[i] >= curmin[i] ,forall i
        curMax[0] = curmin[0] = nums[0];

        int res = nums[0];
        for(int i = 1 ; i < n ; i++)
        {
            if(nums[i] == 0) //一定要包含num ,所以直接代入0
            {
                curMax[i] = curmin[i] = 0;  
            }
            else if(nums[i] > 0) //考慮比較的對象 若要產出較大值 由於curMax >= curmin
            { // curMax * num >= curmin * num 故只要檢查num 和 curMax* num 何者較大 curmin反之亦然
                curMax[i] = max(curMax[i-1]*nums[i],nums[i]);
                curmin[i] = min(curmin[i-1]*nums[i],nums[i]);
            }
            else // num < 0 , curMax * num <= curmin * num 
            {
                curMax[i] = max(curmin[i-1]*nums[i],nums[i]);
                curmin[i] = min(curMax[i-1]*nums[i],nums[i]);
            }
            res = max(res,curMax[i]);
        } 
        return res;
    }
};
