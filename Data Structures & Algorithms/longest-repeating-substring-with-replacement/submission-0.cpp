class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>count;
        int res = 0;
        int left = 0 , right = 0;
        int maxf = 0;
        count[s[right]]++;
        maxf = countMax(count);
        while(!(left == right && right == s.size() - 1))
        {
            maxf = countMax(count);
            if(right - left + 1 -maxf <= k) 
            {
                res = max(right - left + 1,res);
                if(right != s.size() -1 )
                {
                    right++;
                    count[s[right]]++;
                }
                else
                {
                    count[s[left]]--;
                    left++;
                }
            }
            else
            {
                count[s[left]]--;
                left++;
            }
        }
        return res;
    }
    int countMax(unordered_map<char,int> count)
    {
        int max = 0;
        for(auto it = count.begin() ; it != count.end() ; it++)
        {
            if(max < it->second)
            {
                max = it->second;
            }
        }
        return max;
    }
};
