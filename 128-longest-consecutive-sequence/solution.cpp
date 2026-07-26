class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std:: unordered_map<int, int> island;
        int MaxLength = 0;
        for (int i : nums){
            if (!island[i]){
                island[i] = island[i-1] + island[i+1] + 1;
                island[i+island[i+1]] = island[i];
                island[i-island[i-1]] = island[i];
                MaxLength = max(MaxLength, island[i]);
            }
        }
        return MaxLength;
    }
};