class Solution {
public:
    void reversingDiagonals(vector<vector<int>>& v){
        int n = v.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(v[i][j], v[j][i]);
            }
        }
    }

    void reverseRows(vector<vector<int>>& v){
        int n = v.size();
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < n/2; j++){
                swap(v[i][j], v[i][n-j-1]);
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        reversingDiagonals(matrix);
        reverseRows(matrix);
    }
};