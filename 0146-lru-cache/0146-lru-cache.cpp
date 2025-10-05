class LRUCache{
    int capacity;
    list<pair<int,int>> items;  // key-value pairs
    unordered_map<int, list<pair<int,int>>::iterator> cache;  

public:
    LRUCache(int cap) : capacity(cap) {}

    void put(int key, int value){
        if (cache.find(key) != cache.end()) {
            items.erase(cache[key]);
        } else if (items.size() == capacity) {
            auto last = items.back();
            cache.erase(last.first);
            items.pop_back();
        }
        items.push_front({key, value});
        cache[key] = items.begin();
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        // move item to front
        auto it = cache[key];
        int value = it->second;
        items.erase(it);
        items.push_front({key, value});
        cache[key] = items.begin();
        return value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */