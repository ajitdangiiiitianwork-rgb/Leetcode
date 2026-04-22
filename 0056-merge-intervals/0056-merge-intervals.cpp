class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2){
        return v1[0] < v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            int& p1 = result[result.size() - 1][0];
            int& p2 = result[result.size() - 1][1];
            int c1 = intervals[i][0];
            int c2 = intervals[i][1];

            if(c1 <= p2){
                // merge
                p1 = min(p1, c1);
                p2 = max(p2, c2);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};