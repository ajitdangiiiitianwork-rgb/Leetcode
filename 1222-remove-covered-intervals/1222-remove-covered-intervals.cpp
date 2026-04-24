class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2){
        if(v1[0] != v2[0]) return v1[0] < v2[0];
        return v1[1] > v2[1];  // Same start: sort by end DESCENDING
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        int maxEnd = intervals[0][1];
        result.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][1] > maxEnd){
                // Not covered - add to result
                result.push_back(intervals[i]);
                maxEnd = intervals[i][1];
            }
            // If intervals[i][1] <= maxEnd, it's covered - skip it
        }
        
        return result.size();
    }
};