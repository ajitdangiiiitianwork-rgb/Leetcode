class Solution {
public:
    static bool cmp (vector<int>& v1, vector<int>& v2){
        if(v1[1] != v2[1]) return v1[1] < v2[1];
        return v1[2] < v2[2];
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), cmp);

        map<int, int> count;
        for(int i = 0; i < trips.size(); i++){
            count[trips[i][1]] += trips[i][0];
            count[trips[i][2]] -= trips[i][0];
        }

        int numOfPass = 0;
        for(auto &p : count){
            numOfPass += p.second;
            if(numOfPass > capacity) return false;
        }

        return true;
    }
};