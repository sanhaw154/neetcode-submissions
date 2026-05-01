class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> existing;
        int max_len = 0;
        int left = -1;

        for(int right = 0 ; right < s.size() ; right++)
        {
            if(existing.count(s[right]))
            {
               if(left < existing[s[right]])
                {
                    left = existing[s[right]];
                }
            }
            existing[s[right]] = right;

            if(max_len < right - left)
            {
                max_len = right - left ;
            }
        }
        return max_len;
    }
};
