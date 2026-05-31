class Solution {
    vector<vector<string>> res;
    vector<string> split;
public:
    vector<vector<string>> partition(string s) {
        backtrack(s,0,0,"");
        return res;
    }
    void backtrack(string& s ,int start, int index,string path)
    {
        if(index == s.size())
        {
            if(start == s.size())
            {
                res.push_back(split);  
            }
            return;
        }
        
        
        path += s[index];
        backtrack(s,start,index+1,path); //不分割 繼續往下
        if(palindrome(s,start,index))//分割 確認當前path是否為palindrome
        {
            split.push_back(path);
            backtrack(s,index+1,index+1,""); //以下一個char為起點
            split.pop_back();
        }
        //不是則不用繼續往下 返回
        return;
    
    }
    bool palindrome(string p,int i ,int j)
    {
        while(i < j)
        {
            if(p[i] != p[j]) return false;
            i++;
            j--;
        }
        // i < j 不成立有兩種情況  i==j or i==j-1(表示前一步i和j相鄰 且那時p[i]==p[j])
        return true;
    }
};
