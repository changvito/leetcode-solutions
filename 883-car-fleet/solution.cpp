class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.empty()){
            return 0;
        }
        stack<int> Fleet;
        vector<pair<int, int>> ReOrder(position.size());
        for (int i = 0; i < position.size(); i++){
            ReOrder[i].first = position[i];
            ReOrder[i].second = speed[i];
        }
        sort(ReOrder.begin(), ReOrder.end());
        reverse(ReOrder.begin(), ReOrder.end());

        for (int i = 0; i < ReOrder.size(); i++){
            if ((!Fleet.empty()) && ((((double)(target - ReOrder[i].first) / ReOrder[i].second))) <= (((double)(target - ReOrder[Fleet.top()].first) / ReOrder[Fleet.top()].second))){
                continue;;
            }
            Fleet.push(i);
        }
        return Fleet.size();
    }    
};