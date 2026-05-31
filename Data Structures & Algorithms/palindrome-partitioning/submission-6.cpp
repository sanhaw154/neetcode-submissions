class Solution {
    vector<vector<string>> res;
    vector<string> split;
public:
    vector<vector<string>> partition(string s) {
        backtrack(s,0);
        return res;
    }
    void backtrack(string& s ,int start)
    {
        if(start == s.size())
        {
            res.push_back(split);
            return;
        }
        for(int end = start ; end < s.size() ; end++)//找一段回文 再往下
        {
            if(isPalindrome(s,start,end))
            {
                split.push_back(s.substr(start,end - start + 1));
                backtrack(s,end+1);
                split.pop_back();
            }
        }
        return;
    
    }
    bool isPalindrome(string& p,int i ,int j)
    {
        if(i == j || j+1 == i) return true;
        return p[i] == p[j] && isPalindrome (p,i+1,j-1);
    }
};
