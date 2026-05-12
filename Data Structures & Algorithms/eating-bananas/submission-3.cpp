class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for(int num : piles)
        {
            if( r < num )
            {
                r = num;
            }
        }

        while( l <= r )
        {
            int mid = l + (r - l) / 2;
            int needhours = 0 ;
            for(int num :piles)
            {
                needhours += ceil(double(num) / mid) ;
            }
            if(needhours <= h) //valid
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
            
        }
        return l ; //不論何種情況 l最後都會是valid域值中最小的
    }
};
