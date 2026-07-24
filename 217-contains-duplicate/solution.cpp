class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std:: unordered_set <int> HashMap;
        for (int i = 0; i < nums.size(); i++ ){
            if (!(HashMap.insert(nums[i]).second)){
                return true;
            }
        }
        return false;
    }
};