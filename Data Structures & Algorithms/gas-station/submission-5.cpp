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

        int curSum = 0;
        int start = 0;
        for(int i = 0 ; i < n ; i++)
        {
            curSum += differ[i];
            if(curSum < 0)
            {
                curSum = 0;
                start = i + 1;
            }
        }
        return start;
    }
};
