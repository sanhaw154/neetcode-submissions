class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int n = s.size();
         vector<vector<bool>> dp(n,vector<bool>(n));
         for(int len = 0 ; len < n ; len++)
         {
            for(int i = 0 ; i < n ; i++)
            {
                int j = i +len;
                if(j >= n) break;
                if(len == 0) dp[i][j] = true;
                else if(len == 1) dp[i][j] = s[i]==s[j];
                else dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
                if(dp[i][j]) res++;
            }
         }
        return res;
    }
};
