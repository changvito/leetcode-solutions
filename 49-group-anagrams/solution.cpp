class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> HashMap;
        for (auto i : strs){
            string original = i;
            std:: sort(i.begin(), i.end());
            HashMap[i].push_back(original);
        }
        vector<vector<string>> ans;
        for (const auto& i : HashMap)
            ans.push_back(i.second);
        return ans;

    }
};