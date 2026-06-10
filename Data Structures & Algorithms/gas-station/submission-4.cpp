class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> differ(n);
        int totalSum = 0;
        for( int i = 0 ; i < n ; i++)
        {
            differ[i] = gas[i] - cost[i];
            totalSum += differ[i];
        }
        if(totalSum < 0 )return -1;

        vector<bool> isStart(n,true);
        int start = 0;
        while(differ[start] < 0)
        {
            start++;
        }
        int end = (start + 1) % n;
        int total = differ[start];
        while(isStart[start] && start != end)
        {
            total += differ[end];
            if(total < 0)
            {   
                end = (end + 1) % n;
                while(start != end)
                {
                    isStart[start] = false;
                    start = (start + 1) % n;
                }

                while(differ[start] < 0)
                {
                    start++;
                }
                total = differ[start];
                end = start;
            }
            end = (end + 1) % n;
        }
        if(start == end) return start;
        else return -1;
    }
};
