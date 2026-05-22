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
        return dfs(word,cur);
    }
    bool dfs(string& word ,TrieNode* cur)
    {
        for(int i = 0 ; i < word.size() ; i++)
        {
            char& c = word[i];
            if(c == '.')
            {   
                for(int j = 0; j < 26 ; j++)
                {
                    if(cur->chara[j]) //找到可遍歷的node
                    {
                        string new_word = word.substr(i+1);
                        if(dfs(new_word,cur->chara[j])) return true;
                    }
                }
                //找不到可取代的character
                    return false;
            }
            else
            {
                if(cur->chara[c-'a'])
                {
                    cur = cur->chara[c-'a'];
                }
                else
                {
                    return false;
                }
            }
        }
        if(cur)return cur->wordEnd;
        return false;
        
    }
};
