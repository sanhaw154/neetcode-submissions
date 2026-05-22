class TrieNode{
    char s ;
  public:
    bool end ;
    TrieNode* chara[26];
    TrieNode(){
        this->s = ' ';
        for (int i = 0; i < 26; i++) {
        this->chara[i] = nullptr;
    }
        end = false;
    }
    TrieNode(char c)
    {
        this->s = c;
        for (int i = 0; i < 26; i++) {
        this->chara[i] = nullptr;
    }
        end = false;
    }
};

class PrefixTree {
    TrieNode* root ;
    
public:
    PrefixTree() {
        this->root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur =root;
        for(auto c : word)
        {
            if(!cur->chara[c-'a'])
            {
                TrieNode* node = new TrieNode(c);
                cur->chara[c-'a'] = node;
                cur = node;
            }
            else
            {
                cur = cur->chara[c-'a'];
            }
        }
        cur->end = true;
    }
    
    bool search(string word) {
        TrieNode* cur =root;
        for(char c : word)
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
        if(cur->end) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur =root;
        for(auto c : prefix)
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
        return true;
    }
};

