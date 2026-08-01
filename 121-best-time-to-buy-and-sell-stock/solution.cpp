class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MinPrice = prices[0];
        int MaxProfit = 0;

        for (int i = 0; i < prices.size(); i++){
            if (prices[i] < MinPrice){
                MinPrice = prices[i];
            }
            else if (prices[i] - MinPrice > MaxProfit){
                MaxProfit = prices[i] - MinPrice;
            }
        }
        return MaxProfit;
    }
};