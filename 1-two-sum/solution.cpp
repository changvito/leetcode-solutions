class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> HashMap;
        for ( int i = 0; i < nums.size(); i++ ){
            int remnant = target - nums[i];
            if (HashMap.find(remnant) != HashMap.end()){
            return {i, HashMap[remnant]};
            }
            HashMap[nums[i]] = i;
        }
        return {};
        
    }
};