class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std:: unordered_map<int, int> FreqCounter;
        for (const auto& x : nums){
            FreqCounter[x]++;
        }
        auto comp = [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        };
        std::priority_queue<pair<int, int>,vector<pair<int, int>>,decltype(comp)> MinHeap(comp);
        for (const auto& x : FreqCounter){
            MinHeap.push(x);
            if (MinHeap.size() > k){
                MinHeap.pop();
            }
        }
        std:: vector<int> ans;
        while (!MinHeap.empty()){
            ans.push_back(MinHeap.top().first);
            MinHeap.pop();
        }
        return ans;
    }
};