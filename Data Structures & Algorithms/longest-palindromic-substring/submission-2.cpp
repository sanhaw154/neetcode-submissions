class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        pair<int,int> pos = {0,0};
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false)); //isPalindrome
        for(int len = 1 ; len <= n ; len++)
        {
            for(int i = 0 ; i < n ; i++)
            {
                int j = i + len - 1;
                if(j > n-1) break;
                
                if(len <= 2) dp[i][j] = (s[i]==s[j]);
                else dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]) ;

                if(dp[i][j] && maxLen < 1 + j - i)
                {
                    maxLen = 1 + j - i;
                    pos = {i,j};
                }
            }
        }
        return s.substr(pos.first,pos.second-pos.first+1);
    }
};
