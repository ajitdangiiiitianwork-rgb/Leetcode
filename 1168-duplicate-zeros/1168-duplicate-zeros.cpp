class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> b;
        for(int i = 0; i < n; i++){
            if(b.size() == n) break;
            b.push_back(arr[i]);
            if(b.size() == n) break;
            if(arr[i] == 0) b.push_back(arr[i]);
        }

        arr = b;
    }
};