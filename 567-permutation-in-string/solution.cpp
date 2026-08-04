class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Window(128,0);
        vector<int> s2Window(128,0);
        for (int i = 0; i < s1.size(); i++){
            s1Window[s1[i]]++;
        }
        int Left = 0;
        for (int Right = 0; Right < s2.size(); Right++){
            s2Window[s2[Right]]++;
            if ((Right - Left + 1) > s1.size()){
                s2Window[s2[Left]]--;
                Left++;
            }
            if ((Right - Left +1) == s1.size()){
                if (s1Window == s2Window){
                    return true;
                }
            }
        }
        return false;
    }
};