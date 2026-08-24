class Solution {
public:
    int findMin(vector<int>& nums) {
        int Left = 0;
        int Right = nums.size() - 1;
        while (Left < Right){
            int Mid = Left + (Right - Left) / 2;
            if (nums[Mid] > nums[Right]){
                Left = Mid + 1;
            }
            else if (nums[Mid] < nums[Right]){
                Right = Mid;
            }
        }
        return nums[Left];
    }
};