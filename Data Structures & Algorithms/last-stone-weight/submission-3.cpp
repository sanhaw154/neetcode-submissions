class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> pq;
        for(int weight : stones)
        {
            pq.push(weight);
        }
        while(pq.size() >= 2)
        {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if(first - second)
            {
                pq.push(first - second);
            }
        }
        if(!pq.empty()) return pq.top();
        return 0;
    }
};
