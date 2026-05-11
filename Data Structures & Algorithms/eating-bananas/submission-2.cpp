class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = max(piles);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        while(l <= r)
        {
            int k = l + (r - l)/2;
            if(isVaildK(piles,k,h))
            {
                minHeap.push(k);
                r = k - 1;
            }
            else
            {
                l = k + 1;
            }
        }
        return minHeap.top();
    }
    
    bool isVaildK(vector<int>& piles, int k , int h)
    {
        int needHours = 0;
        for(int pile : piles)
        {
            needHours += ceil(double(pile)/k);
        }
        if(needHours <= h)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int max(vector<int>& arr)
    {
        int max = 0;
        for(int num : arr)
        {
            if(max < num)
            {
                max = num;
            }
        }
        return max;
    }
};
