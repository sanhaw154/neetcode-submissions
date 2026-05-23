class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int maxWeight = 0;
        for(int weight : stones) //找最大值
        {
            if(maxWeight < weight)
            {
                maxWeight = weight;
            }
        }
        vector<int> bucket(maxWeight+1); //build bucket(0~maxWeight)
        for(int weight : stones)
        {
            bucket[weight]++;
        }

        for(int curWeight = maxWeight; curWeight > 0 ; curWeight--)
        {
            if(bucket[curWeight] % 2 == 1) //bucket中個數為odd
            {
                int small = curWeight - 1; //找比curWeight小的最大值
                while(!bucket[small] && small) //small為0時 即找不到
                {
                    small--;
                }
                if(small) //存在更小的數 可以相減
                {
                    bucket[small]--;
                    bucket[curWeight] = 0;
                    bucket[curWeight-small]++;
                }
                else
                {
                    bucket[curWeight] = 1;
                }
            }
            else //同值的數可以相互抵銷 最後變為0
            {
                bucket[curWeight] = 0;
            }
        }
        for(int i = 0 ; i <= maxWeight ; i++)
        {
            if(bucket[i])
            {
                return i;
            }
        }
        return 0;
    }
};
