class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int RowHead = 0;
        int RowTail = matrix.size() - 1;
        int ColumnHead = 0;
        int ColumnTail = matrix[0].size() - 1;
        while (RowHead <= RowTail){
            int RowMid = RowHead + (RowTail - RowHead) / 2;
            if (target == matrix[RowMid][0]){
                return true;
            }
            else if (target < matrix[RowMid][0]){   
               RowTail = RowMid - 1;
            }
            else {
                RowHead = RowMid + 1;
            }
        }
        if (RowTail < 0){
            return false;
        }
        while (ColumnHead <= ColumnTail){

            int ColumnMid = ColumnHead +(ColumnTail - ColumnHead) / 2;
            if(target == matrix[RowTail][ColumnMid]){
                return true;
            }
            else if (target < matrix[RowTail][ColumnMid]){
                ColumnTail = ColumnMid - 1;
            }
            else{
                ColumnHead = ColumnMid + 1;
            }
        }
        return false;
    }
};