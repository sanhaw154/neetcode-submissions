class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict;
        for(string& word : wordDict)
        {
            dict.insert(word);
        }
        vector<bool> dp(n+1,false);
        dp[n] = true;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int j = i ; j < n ; j++)
            {
                dp[i] = dp[i] || (dict.count(s.substr(i,j-i+1)) && dp[j+1]);
                if(dp[i]) break;
            }
        }
        return dp[0];
    }
};
