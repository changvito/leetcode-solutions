class LRUCache {
private:
    int Max;
    list<pair<int, int>> CacheList;
    unordered_map<int, list<pair<int, int>>::iterator> CacheAddress;
public:
    LRUCache(int capacity) {
        Max = capacity;
    }
    
    int get(int key) {
        if (CacheAddress.find(key) == CacheAddress.end()){
            return -1;
        }
        CacheList.splice(CacheList.end(), CacheList, CacheAddress[key]);
        return CacheAddress[key] -> second;
    }
    
    void put(int key, int value) {
        if (CacheAddress.find(key) != CacheAddress.end()){
            CacheAddress[key] -> second = value;
            CacheList.splice(CacheList.end(), CacheList, CacheAddress[key]);
            return;
        }
        if (CacheList.size() == Max){
            int Temp = CacheList.front().first;
            CacheAddress.erase(Temp);
            CacheList.pop_front();
        }
        CacheList.push_back({key, value});
        CacheAddress[key] = --CacheList.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */