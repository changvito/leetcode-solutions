class Solution {
public:
    int search(vector<int>& nums, int target) {
        int Left = 0;
        int Right = nums.size() - 1;
        while (Left <= Right){
            int Mid = Left + (Right - Left) / 2;
            if (target == nums[Mid]){
                return Mid;
            }
            else if (nums[Mid] >= nums[Left]){
                if (target >= nums[Left] && target < nums[Mid]){
                    Right = Mid - 1;
                }
                else {
                    Left = Mid + 1;
                }
            }
            else {
                if (target > nums[Mid] && target <= nums[Right]){
                    Left = Mid + 1;
                }
                else {
                    Right = Mid - 1;
                }
            }
        }
        return -1;
    }
};