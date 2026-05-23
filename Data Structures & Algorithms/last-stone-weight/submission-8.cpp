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
        int small = maxWeight;
        int curWeight = maxWeight;
        while(curWeight)
        {
            if(bucket[curWeight] % 2 ) //bucket中個數為odd
            {
                int small = min(curWeight - 1,small); //找比curWeight小的最大值  
                while(!bucket[small] && small) //small為0時 即找不到
                {
                    small--;
                }
                if(small) //存在更小的數 可以相減 並只改對應的個數 且因有被敲小 curWeight必不是最後的值
                {
                    bucket[small]--;
                    bucket[curWeight-small]++;
                    curWeight = max(small,curWeight-small); //curWeight-small 可能在 small~curWeight區間
                }
                else //找不到更小的樹 最後會剩下一個 然後不用繼續往下
                {
                    return curWeight;
                }
            }
            else //同值的數可以相互抵銷 最後變為0 最後的值必然不是它
            {
                curWeight--;
                continue;
            }
        }
        //找不到 則都相互抵銷
        return 0;
    }
};
