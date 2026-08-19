class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Window;
        vector<int> MaxArr;
        int Max = 0;
        for (int i = 0; i < nums.size(); i++){
            if (!Window.empty() && Window.front() < i - k + 1){
                Window.pop_front();
            }
            while (!Window.empty() && nums[i] >= nums[Window.back()]){
                Window.pop_back();
            }
            Window.push_back(i);
            if(i >= k - 1){
                MaxArr.push_back(nums[Window.front()]);
            }
        }
        return MaxArr;
    }
};