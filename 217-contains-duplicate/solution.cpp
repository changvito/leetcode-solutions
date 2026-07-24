class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std:: unordered_map <int, int> HashMap;
        for ( int i = 0; i < nums.size(); i++ ){
            if ( HashMap.find(nums[i]) != HashMap.end()){
            return true;
            }
            HashMap[nums[i]] = i;
        }
        return false;
    }
};