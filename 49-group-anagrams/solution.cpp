class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std:: map<array<int, 26>, vector<string>> HashMap;
        for (const string& s : strs){
            array<int, 26> count = {};
            for (char c : s){
                count [c - 'a']++;
            }
            HashMap[count].push_back(s); 
        }
        vector<vector<string>> ans;
        for (auto x : HashMap){
            ans.push_back(x.second);
        }
        return ans;
    }
};