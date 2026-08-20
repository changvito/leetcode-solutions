class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty() || k == 0){
            return {};
        }
        vector<int> MaxArr;
        vector<int> MaxInd(nums.size());
        int Max = 0;
        int Left = 0;
        int Right = 0;
        for (int i = 0; i < nums.size(); i++){
            while (Right > Left && nums[i] >= nums[MaxInd[Right - 1]] ){
                Right--;
            }
            MaxInd[Right] = i;
            Right++;
            if (MaxInd[Left] < i - k + 1){
                Left++;
            }
            if (i >= k - 1){
                MaxArr.push_back(nums[MaxInd[Left]]);
            }
        }
        return MaxArr;
    }
};