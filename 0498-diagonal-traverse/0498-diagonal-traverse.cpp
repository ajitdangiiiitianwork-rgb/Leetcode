class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> res(m*n, 0);
        int k = 0;
        int dir = 1;

        int rowIdx = 0, colIdx = 0;

        while(k < m*n){
            res[k] = mat[rowIdx][colIdx];
            k++;

            int newRowIdx = dir == 1 ? rowIdx - 1 : rowIdx + 1;
            int newColIdx = dir == 1 ? colIdx + 1 : colIdx - 1;

            if(newRowIdx < 0 || newColIdx < 0 || newRowIdx > m-1 || newColIdx > n-1){
                if(dir == 1){
                    if(colIdx == n-1) rowIdx += 1;
                    else colIdx += 1;
                } else {
                    if(rowIdx == m-1) colIdx += 1;
                    else rowIdx += 1;
                }

                dir = -1 * dir;
            } else {
                rowIdx = newRowIdx;
                colIdx = newColIdx;
            }
        }
        return res;
    }
};