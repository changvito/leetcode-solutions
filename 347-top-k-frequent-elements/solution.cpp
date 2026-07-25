class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std:: unordered_map <int, int> HashMap;
        for (const auto& x : nums){
            HashMap[x]++;
        }
        std:: vector<pair<int, int>> HashVec(HashMap.begin(), HashMap.end());
        std:: sort(HashVec.begin(),HashVec.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });
        vector<int> ans;
        for (int i = 0; i < k; i++){
            ans.push_back(HashVec[i].first);
        }
        return ans;
    }
};