class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() == 0 || s.length() < t.length()){
            return "";
        }
        vector<int> tWindow(128,0);
        vector<int> sWindow(128,0);
        for (int i = 0; i < t.size(); i++){
            tWindow[t[i]]++;
        }
        int Count = t.length();
        int Minimum = INT_MAX;
        int MinLeft = 0;
        int Left = 0;
        int Right = 0;
        while (Right < s.size()){
            if(tWindow[s[Right]] > 0){
                Count--;
            }
            tWindow[s[Right]]--;
            Right++;
            while (Count == 0){
                if(Right - Left < Minimum){
                    Minimum = Right - Left;
                    MinLeft = Left;
                }
                tWindow[s[Left]]++;
                if(tWindow[s[Left]] > 0){
                    Count++;
                }
                Left++;
            }
        }
        return Minimum == INT_MAX ? "" : s.substr(MinLeft, Minimum);
    }
};