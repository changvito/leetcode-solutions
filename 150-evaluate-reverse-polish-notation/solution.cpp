class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> RPN;
        for (const string& c : tokens){
            if (c == "+"){
                int Second = RPN.top();
                RPN.pop();
                int First = RPN.top();
                RPN.pop();
                RPN.push(First + Second);
            }
            else if (c == "-"){
                int Second = RPN.top();
                RPN.pop();
                int First = RPN.top();
                RPN.pop();
                RPN.push(First - Second);
            }
            else if (c == "*"){
                int Second = RPN.top();
                RPN.pop();
                int First = RPN.top();
                RPN.pop();
                RPN.push(First * Second);
            }
            else if (c == "/"){
                int Second = RPN.top();
                RPN.pop();
                int First = RPN.top();
                RPN.pop();
                RPN.push(First / Second);
            }
            else{
                RPN.push(stoi(c));
            }
        }
        return RPN.top();
    }
};