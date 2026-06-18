class Solution {
    vector<vector<int>>memo;
public:
    int numDecodings(string s) {
        memo.assign(s.size(),vector<int>(s.size()+1,-1)); // 1 <=len<= n
        return dfs(0,1,s);
    }
    int dfs(int index , int len ,string s) // isfirst 0: 不在index和index+1之間切一刀 1: 切一刀
    {
        if(index == s.size() && len == 1) return 1; //表前面都切好
        else if (index == s.size()) return 0; //最後一段還沒切 return

        if(memo[index][len] != -1) return memo[index][len];

        string cur = s.substr(index - len + 1, len);
        if (cur[0] == '0' || (stoi(cur)) < 1 || (stoi(cur)) > 26 ) return 0; //當前str非法 

        int cut = dfs(index + 1 , 1 , s);
        int preceed = dfs(index + 1 , len + 1 , s);
        memo[index][len] = cut + preceed;
        return cut + preceed;
    }
};
