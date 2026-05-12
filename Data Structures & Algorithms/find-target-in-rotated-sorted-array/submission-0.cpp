class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        if(nums[left] > nums[right])
        {
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
            if(target >= nums[0])//去左側sorted array找
            {
                right = left;
                left = 0;
            }
            else
            {
                left = right;
                right = nums.size()-1;
            }
        }//設定好left和right

        while(left <= right)
        {
            int mid = left + (right-left)/2 ;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};
