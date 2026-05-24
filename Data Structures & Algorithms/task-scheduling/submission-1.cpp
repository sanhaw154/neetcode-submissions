class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26]={};
        for(char c : tasks) //O(m)
        {
            count[c-'A']++;
        }
        priority_queue<int> maxHeap;
        for(int i = 0 ; i < 26 ; i++)//O(1)
        {
            if(count[i])
            {
                maxHeap.push(count[i]);
            }
        }

        int time = 0;
        queue<pair<int, int>> q;
        
        while(!maxHeap.empty() || !q.empty())
        {
            time++;
            if(!maxHeap.empty())
            {
                int freq = maxHeap.top();
                maxHeap.pop();
                if(--freq)
                {
                    q.push({freq,time + n});
                }
            }
            else
            {
                time = q.front().second;
            }
            
            if(!q.empty() && q.front().second == time )
            {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
