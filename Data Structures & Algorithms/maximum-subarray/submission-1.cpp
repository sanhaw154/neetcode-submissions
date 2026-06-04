class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divide(nums,0,nums.size()-1);
    }
    int divide(vector<int>& num,int start,int end)
    {
        
        if(start > end) return INT_MIN;
        if(start == end) return num[start];
        int mid = start + (end-start)/2;

        int curSum = 0;
        int leftSum = 0;
        int rightSum = 0;
        for(int i = mid - 1; i >=start ; i--)
        {
            curSum += num[i];
            leftSum = max(leftSum,curSum);
        }
        curSum = 0;
        for(int i = mid + 1; i <= end ; i++)
        {
            curSum += num[i];
            rightSum = max(rightSum,curSum);
        }

        return max(divide(num,start,mid-1),max(divide(num,mid+1,end),leftSum + rightSum + num[mid]));
    }
};
