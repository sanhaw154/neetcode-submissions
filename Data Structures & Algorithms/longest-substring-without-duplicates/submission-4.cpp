class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> existing;
        int max_len = 0;
        int left = -1, right = -1;

        for(int i = 0; i < s.size(); i++)
        {
            right++;
            if(!existing.count(s[i]))
            {
                existing.insert({s[i],i});
            }
            else
            {
                if(left < existing[s[i]])
                {
                    left = existing[s[i]];
                }
                existing[s[i]] = i;
            }

            if(max_len < right - left)
            {
                max_len = right - left ;
            }
        }
        return max_len;
    }
};
