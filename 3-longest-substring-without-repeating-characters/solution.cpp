class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> LastPos(128, -1);
        int Left = 0;
        int Max = 0;
        for (int Right = 0; Right < s.size(); Right++){
            if (LastPos[s[Right]] >= Left){
                Left = LastPos[s[Right]] + 1;
            }
            LastPos[s[Right]] = Right;
            Max = max(Max, Right - Left + 1);
        }
        return Max;
    }
};