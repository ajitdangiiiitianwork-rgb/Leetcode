class Solution {
public:
    vector<vector<int>> dirs = {
        {0, 1}, // move to right
        {1, 0}, // move to down
        {0, -1},// move to left
        {-1, 0},// move to up
    };

    void BFS(vector<vector<char>>& grid, int row, int col){
        queue< pair<int,int> > q;
        q.push({row, col});

        grid[row][col] = '0';

        while(!q.empty()){
            int size  = q.size();
            for(int i = 0; i < size; i++){

                int cR = q.front().first;
                int cC = q.front().second;
                q.pop();

                for(int j = 0; j < dirs.size(); j++){
                    int nR = cR + dirs[j][0];
                    int nC = cC + dirs[j][1];

                    if((nR >= grid.size()) || (nC >= grid[0].size()) || (nR < 0) || (nC < 0) || (grid[nR][nC] == '0')) 
                        continue;

                    grid[nR][nC] = '0'; // this has been marked as visited
                    q.push({nR, nC});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int countIslands = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    // 1. increase the count of islands
                    // 2. run bfs to mark all the nearby lands visited

                    countIslands += 1;

                    // BFS code
                    BFS(grid, i, j);
                }
            }
        }

        return countIslands;
    }
};