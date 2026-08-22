class Solution {
public:
    int search(vector<int>& nums, int target) {
        int Right = nums.size() - 1;
        int Left = 0;
        while (Left <= Right){
            int Mid = Left + (Right - Left) / 2;
            if (target == nums[Mid]){
                return Mid;
            }
            else if (target < nums[Mid]){
                Right = Mid - 1;
            }
            else {
                Left = Mid + 1;
            } 
        }
        return -1;
    }
};