class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char,int> HashMap;
        for (int i = 0; i < s.size(); i ++){
            HashMap[s[i]]++;
        }
        for (int i = 0; i < t.size(); i ++){
            HashMap[t[i]]--;
        }
        if (s.size() != t.size()){
            return false;
        }
        else{
            for (int i = 0; i < s.size(); i++){
                if (HashMap[s[i]] != 0)
                    return false;
            }
        }
        return true;
    }
};