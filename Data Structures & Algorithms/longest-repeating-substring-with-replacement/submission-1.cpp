class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>count;
        int res = 0;
        int left = 0;
        int maxf = 0;
        for(int right = 0; right < s.size(); right++)
        {
            count[s[right]]++;
            maxf = max(maxf,count[s[right]]);
            
            while(right - left + 1 -maxf > k)
            {
                count[s[left]]--;
                left++;
            }
            res = max(res,right - left + 1);
        }
        return res;
    }
};
