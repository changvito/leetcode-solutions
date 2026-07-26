class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std:: unordered_set<char> row[9];
        std:: unordered_set<char> column[9];
        std:: unordered_set<char> boxes[9];
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                char ch = board[i][j];
                if (ch == '.') continue;
                if (!row[i].insert(ch).second || !column[j].insert(ch).second || 
                !boxes[(i/3)*3+j/3].insert(ch).second){
                    return false;
                }
            }
        }
        return true;        
    }
};