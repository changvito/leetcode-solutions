class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std:: unordered_set<int> NumSet(nums.begin(), nums.end());
        int LongestConsecutiveSequence = 0;
        for (int i : NumSet){
            if (NumSet.find(i - 1) ==  NumSet.end()){
                int CurrentNum = i;
                int CurrentSequence = 1;
                while (NumSet.find(CurrentNum + 1) != NumSet.end()){
                    CurrentNum += 1;
                    CurrentSequence += 1;
                }
                LongestConsecutiveSequence = max(LongestConsecutiveSequence, CurrentSequence);
            }
        }
        return LongestConsecutiveSequence;
    }
};