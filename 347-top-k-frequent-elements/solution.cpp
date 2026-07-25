class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std:: unordered_map<int, int> FreqCounter;
        for (const auto& x : nums){
            FreqCounter[x]++;
        }
        std:: vector<vector<int>> bucket(nums.size()+1);
        for (const auto& x : FreqCounter){
            int num = x.first;
            int freq = x.second;
            bucket[freq].push_back(num);
        }
        std::vector<int> ans;
        for (int i = nums.size(); i >= 0; --i){
            for (const auto& x : bucket[i]){
                ans.push_back(x);
                if (ans.size() == k){
                    return ans;
                }
            }
        }
        return ans;
    }
};