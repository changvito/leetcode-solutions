class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int Slow = nums[0];
        int Fast = nums[0];
        do {
            Slow = nums[Slow];
            Fast = nums[nums[Fast]];
        } while (Slow != Fast);
        Slow = nums[0];
        while (Slow != Fast) {
            Slow = nums[Slow];
            Fast = nums[Fast];
        }
        return Slow;
    }
};