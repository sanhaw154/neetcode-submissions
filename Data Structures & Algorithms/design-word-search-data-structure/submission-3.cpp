class TrieNode{
    public:
    TrieNode* chara[26] = {};
    bool wordEnd = false;
};


class WordDictionary {
public:
    TrieNode* root = nullptr ;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word)
        {
            if(!cur->chara[c-'a'])
            {
                TrieNode* node = new TrieNode();
                cur->chara[c-'a'] = node;
                cur = node;
            }
            else
            {
                cur = cur->chara[c-'a'];
            }
        }
        cur->wordEnd = true;
    }
    
    bool search(string word) {
        if(!root) return false;
        TrieNode* cur = root;
        int pos = 0;
        return dfs(word,pos,cur);
    }
    bool dfs(string& word ,int str_pos,TrieNode* cur)
    {
        for(int i = str_pos ; i < word.size() ; i++)
        {
            char& c = word[i];
            if(c == '.')
            {   
                for(int j = 0; j < 26 ; j++)
                {
                    if(cur->chara[j]) //找到可遍歷的node
                    {
                        if(dfs(word,i+1,cur->chara[j])) return true;
                    }
                }
                //找不到可取代的character
                    return false;
            }
            else //找該char是否有所對應的node可前往 
            {
                if(cur->chara[c-'a']) //有記錄過
                {
                    cur = cur->chara[c-'a'];
                }
                else //沒有
                {
                    return false;
                }
            }
        }
        //遍歷完整個word cur停的位置決定是否有記錄
        return cur->wordEnd; 
        
        
    }
};
