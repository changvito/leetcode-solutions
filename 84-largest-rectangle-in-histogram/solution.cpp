class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> Rec;
        int Largest = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++){
            while(!Rec.empty() && heights[i] < heights[Rec.top()]){
                int temp = Rec.top();
                Rec.pop();
                int width = Rec.empty()? i : i - Rec.top() - 1;
                Largest = max(Largest, heights[temp] * width);
            }
            Rec.push(i);
        }
        return Largest;
    }
};