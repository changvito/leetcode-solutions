class Solution {
public:
    int maxArea(vector<int>& height) {
        int Left = 0;
        int Right = height.size() - 1;
        int Max = 0;
        while (Left < Right){
            Max = max(Max, min(height[Left], height[Right]) * (Right - Left));
            if (height[Left] <= height[Right]){
                Left++;
            }
            else{
                Right--;
            }
        }
        return Max;
    }
};