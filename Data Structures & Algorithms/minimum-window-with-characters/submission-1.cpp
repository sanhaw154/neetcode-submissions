class Solution {
public:
    string minWindow(string s, string t) {
        int resLen = INT_MAX;
        pair<int,int> resStrPos= {-1,-1};
        unordered_map<int,int> countT, window;
        int have = 0;
        for(char c : t )
        {
            countT[c]++; //計算t的字母個數
        }
        int need = countT.size();

        int l = 0;
        for(int r = 0 ; r < s.size() ; r++ )
        {
            char c = s[r];
            window[c]++;

            if(countT.count(c) && window[c] == countT[c])
            {
                have ++ ; //只有dict有的字母 可以加入have裡面 
            }
            while(have == need) //在window裡有包含所有dict裡有的character
            {
                if(r - l + 1 < resLen)
                {
                    resLen = r - l + 1;
                    resStrPos.first = l;
                    resStrPos.second = r;
                }
                if(countT.count(s[l]) && window[s[l]] == countT[s[l]] )//l在移動後會使該substring變成invalid 
                {
                    have --; //該字母在window裡的字數在left移動後會少1 所以變為invalid
                }
                window[s[l]]--; //left移動
                l++;
            }
        }
        if(resLen == INT_MAX)//沒有滿足的substring
        {
            return "";
        }
        else
        {
            return s.substr(resStrPos.first,resLen);
        }
        
    }
};
