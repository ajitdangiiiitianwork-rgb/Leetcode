class Solution {
public:
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Using Bucket Sort Algo
        vector<int> buckets(1001, 0);
        for(auto& p : trips){
            int pass = p[0];
            int start = p[1];
            int end = p[2];

            buckets[start] = buckets[start] + pass;
            buckets[end] = buckets[end] - pass;
        }

        int passengers = 0;
        for(int i = 0; i < buckets.size(); i++){
            passengers += buckets[i];
            if(passengers > capacity) return false;
        }

        return true;
    }
};