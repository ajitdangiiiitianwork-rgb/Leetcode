class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int n = firstList.size();
        int m = secondList.size();

        int i = 0; // firstList pointer
        int j = 0; // secondList pointer

        while(i < n && j < m){
            int e1 = firstList[i][1];
            int s1 = firstList[i][0];
            int e2 = secondList[j][1];
            int s2 = secondList[j][0];

            if(e1 >= s2 && e2 >= s1){
                // intersection is present
                result.push_back({max(s1, s2), min(e1, e2)});
            }

            if(e1 < e2) i = i + 1;
            else j = j + 1;
        }

        return result;
    }
};