class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> result;

        for(int i = 0; i < timePoints.size(); i++){
            int h = stoi(timePoints[i].substr(0,2));
            int m = stoi(timePoints[i].substr(3));

            result.push_back(h*60 + m);
        }
        sort(result.begin(), result.end());

        int minDiff = INT_MAX;
        for(int i = 0; i < result.size()-1; i++){
            if(result[i+1] - result[i] < minDiff) minDiff = result[i+1] - result[i];
        }

        minDiff = min(minDiff, 1440 - result[result.size()-1] + result[0]);
        return minDiff;
    }
};