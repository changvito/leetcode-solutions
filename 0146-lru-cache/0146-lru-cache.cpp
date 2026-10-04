class LRUCache {
private:
    int Cap;
    list<pair<int, int>> CacheList;
    unordered_map <int, list<pair<int, int>>::iterator> CacheMap;
public:
    LRUCache(int capacity) {
        Cap = capacity;
    }
    
    int get(int key) {
        if (CacheMap.find(key) == CacheMap.end()){
            return -1;
        }
        CacheList.splice(CacheList.end(), CacheList, CacheMap[key]);
        return CacheMap[key] -> second;
    }
    
    void put(int key, int value) {
        if (CacheMap.find(key) != CacheMap.end()){
            CacheMap[key] -> second = value;
            CacheList.splice(CacheList.end(), CacheList, CacheMap[key]);
            return;
        }
        if (CacheList.size() == Cap){
            int DeleteKey = CacheList.front().first;
            CacheMap.erase(DeleteKey);
            CacheList.pop_front();
        }
        CacheList.push_back({key, value});
        CacheMap[key] = --CacheList.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */