class Solution {
public:
    bool isValid(string s) {
        if (s.empty()){
            return true;
        }
        stack<char> VP;
        unordered_map<char, char> Table = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for (char c : s){
            if (Table.find(c) == Table.end()){
                VP.push(c);
            }
            else{
                if (VP.empty() || VP.top() != Table[c]){
                    return false;
                }
                VP.pop();
            }
        }
        return VP.empty();
    }
};