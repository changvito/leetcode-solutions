class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> Count(128, 0);
        int Left = 0;
        int MaxCount = 0;
        int Longest = 0;
        for (int Right = 0; Right < s.size(); Right++){
            Count[s[Right]]++;
            MaxCount = max(MaxCount, Count[s[Right]]);
            if(Right - Left + 1 - MaxCount > k){
                Count[s[Left]]--;
                Left++;
            }
            Longest = max(Longest, Right - Left + 1);
        }
        return Longest;
    }
};