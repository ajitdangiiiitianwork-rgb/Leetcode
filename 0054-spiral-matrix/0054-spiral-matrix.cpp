class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int maxr = matrix.size();
        int maxc = matrix[0].size();
        int minr = 0;
        int minc = 0;
        int i;
        int n = maxc*maxr;

        while(minr<maxr && minc<maxc){
            for(i=minc; i<maxc; i++)
                v.push_back(matrix[minr][i]);
            minr++;
            if(v.size() == n) break;

            for(i=minr; i<maxr; i++)
                v.push_back(matrix[i][maxc-1]);
            maxc--;
            if(v.size() == n) break;

            for(i=maxc-1; i>=minc; i--)
                v.push_back(matrix[maxr-1][i]);
            maxr--;
            if(v.size() == n) break;

            for(i=maxr-1; i>=minr; i--)
                v.push_back(matrix[i][minc]);
            minc++;
            if(v.size() == n) break;
            
        }
        
        return v;

    }
};