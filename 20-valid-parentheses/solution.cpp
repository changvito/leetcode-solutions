class Solution {
public:
    bool isValid(string s) {
        if (s.empty()){
            return true;
        }
        stack<char> VP;
        for (char c : s){
            if (c == '(' || c =='[' || c == '{'){
                VP.push(c);
            }
            else if ( c == ')'){
                if (VP.empty() || VP.top() != '('){
                    return false;
                }
                VP.pop();
            }
            else if ( c == ']'){
                if (VP.empty() || VP.top() != '['){
                    return false;
                }
                VP.pop();
            }
            else if ( c == '}'){
                if (VP.empty() || VP.top() != '{'){
                    return false;
                }
                VP.pop();
            }
        }
        if (!VP.empty()){
            return false;
        }
        return true;
    }    
};