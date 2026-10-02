class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int Low = 1;
        int High = nums.size() - 1;

        while (Low < High) {
            int Mid = Low + (High - Low) / 2;
            int Count = 0;
            for (int Num: nums){
                if (Num <= Mid){
                    Count++;
                }
            }
            if (Count > Mid){
                High = Mid;
            }
            else {
                Low = Mid + 1;
            }
        }
        return Low;
    }
};