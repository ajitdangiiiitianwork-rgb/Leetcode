class Solution {
public:
    void backtrack(int row, unordered_set<int>& cols, unordered_set<int>& diags, unordered_set<int>& antidi,
    vector<vector<string>>& boards, int n, vector<vector<char>>& game){
        if(row == n){
            // add game to boards
            vector<string> temp;
            for(int i = 0; i < n; i++){
                string s = "";
                for(int j = 0; j < n; j++){
                    s += game[i][j];
                }

                temp.push_back(s);
            }

            boards.push_back(temp);
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

            game[row][col] = 'Q';
            backtrack(row + 1, cols, diags, antidi, boards, n, game);
            game[row][col] = '.';

            cols.erase(col);
            diags.erase(dia);
            antidi.erase(anti);
        }
    }

    int totalNQueens(int n) {
        unordered_set<int> cols;
        unordered_set<int> diags;
        unordered_set<int> antidi;

        vector<vector<string>> boards;
        vector<vector<char>> game(n, vector<char>(n, '.'));

        backtrack(0, cols, diags, antidi, boards, n, game);
        return boards.size();
    }
};