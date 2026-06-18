class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[n] = 1;
        if(s[n-1] != '0') dp[n-1] = 1;
        else dp[n-1] = 0;
        for(int i = n-2 ; i >= 0 ; i--)
        {
            if (s[i] == '0') 
            {
                dp[i] = 0;
            }
            else if(stoi(s.substr(i,2)) <= 26) //1 <= stoi(s.substr(i,2)) <= 26 這寫法會變成 先1 <= stoi(s.substr(i,2)) 再<= 26判斷 所以實際上效果等同 stoi(s.substr(i,2)) >=1
            {
                dp[i] = dp[i+1] + dp[i+2];
            } 
            else
            {
                dp[i] = dp[i+1];
            }     
        }
        return dp[0];
    }
};
