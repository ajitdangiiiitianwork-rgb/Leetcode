class Solution {
public:
    void backtrack(int row, unordered_set<int>& cols, unordered_set<int>& diags, unordered_set<int>& antidi, int n, int& res){
        if(row == n){
            // increment the counter
            res++;
            return;
        }

        for(int col = 0; col < n; col++){
            if(cols.find(col) != cols.end()) continue;

            int dia = col - row;
            if(diags.find(dia) != diags.end()) continue;

            int anti = col + row;
            if(antidi.find(anti) != antidi.end()) continue;

            cols.insert(col);
            diags.insert(dia);
            antidi.insert(anti);

            backtrack(row + 1, cols, diags, antidi, n, res);

            cols.erase(col);
            diags.erase(dia);
            antidi.erase(anti);
        }
    }

    int totalNQueens(int n) {
        unordered_set<int> cols;
        unordered_set<int> diags;
        unordered_set<int> antidi;
        int res = 0;
        backtrack(0, cols, diags, antidi, n, res);
        return res;
    }
};