class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> adjaceny(n,vector<int>(n,1001));
        for(vector<int>& flight : flights)
        {
            adjaceny[flight[0]][flight[1]] = flight[2];
        }
        vector<vector<int>> spl(k+2,vector<int>(n,1001));
        spl[0][src] = 0;
        for(int t = 1 ; t <= k+1 ; t++)
        {
            for(int i = 0 ; i < n ; i++)
            {
                bool isRelax = false;
                for(int u = 0 ; u < n ; u++)
                {
                    if(adjaceny[u][i] == 1001) continue;
                    if(spl[t-1][i] > spl[t-1][u] + adjaceny[u][i]) 
                    {
                        spl[t][i] = spl[t-1][u] + adjaceny[u][i];
                        isRelax = true;
                    }
                }
                if(!isRelax) spl[t][i] = spl[t-1][i];
            }
        }
        if(spl[k+1][dst] != 1001)return spl[k+1][dst];
        return -1;
    }
};
