class Solution {
public:
    int ConsecutiveSides(vector<int>& v){
        sort(v.begin(), v.end());
        int maxConsSides = 1, maxi = 1;
        for(int i = 1; i < v.size(); i++){
            if(v[i] == v[i-1]+1){ // consecutive sides
                maxi++;
            }
            else maxi = 1;
            maxConsSides = max(maxConsSides, maxi);
        }
        
        return maxConsSides;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        return pow(1 + min(ConsecutiveSides(hBars), ConsecutiveSides(vBars)), 2);
    }
};