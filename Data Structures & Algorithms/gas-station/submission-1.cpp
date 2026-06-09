class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int start = 0 ; start < n ; start++)
        {
            if(traversal(gas,cost,start)) return start;
        }
        return -1;
    }
    bool traversal(vector<int>& gas, vector<int>& cost, int start)
    {
        int n = gas.size();
        int curGas = gas[start] - cost[start];
        if(curGas < 0) return false;
        for(int i = start + 1 ; i != start ; i++)
        {
            if( i == n) i = 0;
            if(i == start) break;  
            
            curGas = curGas - cost[i] + gas[i];
            if(curGas < 0) return false; 
            
        }
        return true;
    }
};
