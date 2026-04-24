class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i;
        for(i = 0; i < intervals.size(); i++){
            // check for intersection with the new interval
            if(intervals[i][1] >= newInterval[0] && newInterval[1] >= intervals[i][0]){
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            } else {
                if(intervals[i][0] > newInterval[1]) {
                    result.push_back(newInterval);
                    break;
                } else {
                    result.push_back(intervals[i]);
                }
            }
        }

        if(i == intervals.size()) result.push_back(newInterval);

        for(int j = i; j < intervals.size(); j++){
            result.push_back(intervals[j]);
        }

        return result;
    }
};