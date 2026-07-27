class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        std:: sort(nums.begin(), nums.end());
        int Current = 1;
        int Max = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i-1]){
                continue;
            }
            if (nums[i] == nums[i-1] + 1){
                Current ++;
            }
            else{
                Current = 1;
            }
            Max = max(Max, Current);
        }
        return Max;
    }
};