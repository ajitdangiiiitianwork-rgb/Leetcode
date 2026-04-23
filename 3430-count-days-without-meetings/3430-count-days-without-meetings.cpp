class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2){
        return v1[0] < v2[0];
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        // Using the approach of merge intervals
        sort(meetings.begin(), meetings.end(), cmp);
        vector<vector<int>> result;
        result.push_back(meetings[0]);

        for(int i = 1; i < meetings.size(); i++){
            int& p2 = result[result.size() - 1][1];
            int c1 = meetings[i][0];
            int c2 = meetings[i][1];

            if(c1 <= p2){
                // merge
                p2 = max(p2,c2);
            } else result.push_back({c1,c2});
        }

        // Now the merging is done;
        if(result.size() == 1) {
            return (result[0][0] - 1) + (days - result[0][1]); 
        }

        else {
            int count = 0;
            count = count + (result[0][0] - 1);
            int j;
            for(j = 1; j < result.size(); j++){
                count = count + result[j][0] - result[j-1][1] - 1;
            }

            count = count + (days - result[j-1][1]);
            return count;
        }

        return 0;
        
    }
};