class Solution {
public:
    bool isPalindrome(string s) {
        std:: string LowerCaseString;
        for (char c : s){
            if (isalnum(c)){
                LowerCaseString += tolower(c);
            }
        }
        for (int i = 0; i < LowerCaseString.size()/2; i++){
            if (LowerCaseString[i] != LowerCaseString[LowerCaseString.size() - i - 1]){
                return false;
            }
        }
        return true;
    }
};