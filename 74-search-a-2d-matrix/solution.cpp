class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int Head = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int Tail = m * n - 1;
        while (Head <= Tail){
            int Mid = Head + (Tail - Head) / 2;
            if (target == matrix[Mid / n][Mid % n]){
                return true;
            }
            else if (target < matrix[Mid / n][Mid % n]){
                Tail = Mid - 1;
            }
            else{
                Head = Mid + 1;
            }
        }
        return false;
    }
};