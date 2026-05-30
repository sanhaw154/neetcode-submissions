class Solution {
    vector<vector<string>> res;
    vector<string> split;
public:
    vector<vector<string>> partition(string s) {
        backtrack(s,0);
        return res;
    }
    void backtrack(string& s, int start)
    {
        if(start == s.size())
        {
            res.push_back(split);
            return;
        }
        for(int end = start; end < s.size() ; end++)
        {
            if(isPalindrome(s,start,end))
            {
                split.push_back(s.substr(start,end-start+1));
                backtrack(s,end+1);
                split.pop_back();
            }
        }
        return;
    }
    bool isPalindrome(string& s,int i,int j)
    {
        while(i < j)
        {
            if(i == j) return true;
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
};
