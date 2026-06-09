class Solution {
public:
    bool canJump(vector<int>& nums) {
        int next = nums.size()-1;
        int front = next-1;
        while(front >= 0) //next != 0 時
        {
            if(front + nums[front] >= next)
            {
                next = front;
                front = next - 1;
            }
            else
            {
                front--;
            }
        }
        if(!next) return true;
        else return false;
    }
};
