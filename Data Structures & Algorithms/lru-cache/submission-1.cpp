class LRUCache {
public:
    list<int> LRUstack;
    unordered_map<int,pair<int, list<int>::iterator>> map;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!map.count(key)) return -1;
        
        LRUstack.erase(map[key].second);
        LRUstack.push_back(key);
        map[key].second = --LRUstack.end();
        return map[key].first;
    }
    
    void put(int key, int value) {
        if(map.count(key))
        {
            LRUstack.erase(map[key].second);
        }
        if(LRUstack.size() == capacity)
        {
            auto head = LRUstack.front();
            map.erase(head);
            LRUstack.pop_front();
        }
        map[key].first = value;
        LRUstack.push_back(key);
        map[key].second = --LRUstack.end();
    }
};


