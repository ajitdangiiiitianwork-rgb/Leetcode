class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for(int i = arr.size()-1; i >= 1; i--){
            int diff = arr[i] - arr[i-1];
            if(diff < minDiff) minDiff = diff;
        }
        vector<vector<int>> result;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i-1] == minDiff){
                vector<int> ans;
                ans.push_back(arr[i-1]);
                ans.push_back(arr[i]);
                result.push_back(ans);
            }
        }
        return result;
    }
};