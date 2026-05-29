class Solution {
    vector<string> res;
    string pare;
public:
    vector<string> generateParenthesis(int n) {
        int left = 0,right = 0;
        backtrack(left,right,n);
        return res;
    }
    void backtrack(int left,int right,int n)
    {
        if(left == n && right == n) res.push_back(pare);
        if(left < n)
        {
            pare += '(';
            backtrack(left + 1,right,n);
            pare.erase(pare.size()-1);
        }
        if(left > right )
        {
            pare += ')';
            backtrack(left,right + 1,n);
            pare.erase(pare.size()-1);
        }
        return;
    }
};
