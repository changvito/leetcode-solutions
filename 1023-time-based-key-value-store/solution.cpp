class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> StoreTable;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        StoreTable[key].push_back({timestamp, value});
        
    }
    
    string get(string key, int timestamp) {
        if (StoreTable.find(key) == StoreTable.end()){
            return "";
        }
        auto& pairs = StoreTable[key];
        auto it = upper_bound(pairs.begin(), pairs.end(), make_pair(timestamp, string("")),[](const pair<int, string>& a, const pair<int, string>& b) {
                return a.first < b.first;
        });
        if (it == pairs.begin()) return "";
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */