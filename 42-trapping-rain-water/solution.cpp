class Solution {
public:
    int trap(vector<int>& height) {
        int Left = 0;
        int Right = height.size() - 1;
        int LeftMax = 0;
        int RightMax = 0;
        int Water = 0;
        while (Left < Right){
            if (height[Left] < height[Right]){
                if (height[Left] >= LeftMax){
                    LeftMax = height[Left];
                }
                else{
                    Water += LeftMax - height[Left];
                }
                Left++;
            }
            else {
                if (height[Right] >= RightMax){
                    RightMax = height[Right];
                }
                else{
                    Water += RightMax - height[Right]; 
                }
                Right--;
            }
        }
        return Water;
    }
};