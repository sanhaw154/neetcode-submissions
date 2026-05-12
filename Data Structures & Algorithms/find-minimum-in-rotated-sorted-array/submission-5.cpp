class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        if(nums[left] < nums[right]) //當前區間no rotate
        {
            return nums[left];
        }
        while(left + 1 < right)//相鄰時stop
        {
            int mid = left + (right-left)/2 ;
            
            if(nums[mid] >= nums[left])
            {
                left = mid;
            }
            else if(nums[mid] <= nums[right])
            {
                right = mid ;
            }
        }
        return nums[right];

    }
};
