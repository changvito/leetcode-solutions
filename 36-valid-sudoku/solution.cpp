class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std:: unordered_set<char> CheckDuplicate;
        //Check Row
        for (int i = 0; i < 9; i++){    
            CheckDuplicate.clear();
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    if (!CheckDuplicate.insert(board[i][j]).second){
                        return false;
                    }
                }
            }
        }
        //Check Column
        for (int i = 0; i < 9; i++){
            CheckDuplicate.clear();
            for (int j = 0; j < 9; j++){
                if (board[j][i] != '.'){
                    if (!CheckDuplicate.insert(board[j][i]).second){
                        return false;
                    }
                }
            }
        }
        //Check Sub-Boxes
        CheckDuplicate.clear();
        for (int row = 0; row < 9; row += 3){
            for (int column = 0; column < 9; column += 3){
                CheckDuplicate.clear();
                for (int i = row; i < row + 3; i++){
                    for (int j = column; j < column + 3; j++){
                        if (board[i][j] != '.'){
                            if (!CheckDuplicate.insert(board[i][j]).second){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};