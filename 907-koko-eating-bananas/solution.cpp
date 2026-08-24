class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int Left = 1;
        int Right = 0;
        for (int i = 0; i < piles.size(); i++){
            Right = max(Right, piles[i]);
        }
        int k;
        while (Left <= Right){
            int Mid = Left + (Right - Left) / 2;
            long long Hours = 0;
            for (int i = 0; i < piles.size(); i++){
                Hours += (piles[i] + Mid - 1) / Mid;
            }
            if (Hours <= h){
                k = Mid;
                Right = Mid - 1;
            }
            else if (Hours > h){
                Left = Mid + 1;
            }
        }
        return k;
    }
};