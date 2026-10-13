class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        //Find the Meeting point, but stop at the next point
        int Slow = nums[0];
        int Fast = nums[0];
        do {
            Slow = nums[Slow];
            Fast = nums[nums[Fast]];
        }while (Fast != Slow);

        //Retrieve the Duplicate
        Slow = nums[0];
        while (Fast != Slow){
            Slow = nums[Slow];
            Fast = nums[Fast];
        }
        return Slow;
    }
};