class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> TempStack;
        vector<int> Days(temperatures.size(),0);
        for (int i = 0; i < temperatures.size(); i++){
            while(!TempStack.empty() && temperatures[i] > temperatures[TempStack.top()]){
                int Ind = TempStack.top();
                TempStack.pop();
                Days[Ind] = i -Ind;
            }
            TempStack.push(i);
        }
        return Days;
    }
};