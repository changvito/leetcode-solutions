class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MinPrice = prices[0];
        int MaxProfit = 0;

        for (int i : prices){
            MinPrice = min(i, MinPrice);
            MaxProfit = max(i-MinPrice, MaxProfit);
        }
        return MaxProfit;
    }
};