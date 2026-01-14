class Solution {
public:
    vector<vector<int>> result;
    void f(vector<int> &cand, int t, int idx, vector<int> &subset){
        if(t == 0){
            // found a subset
            result.push_back(subset);   
            return;
        }

        if(idx == cand.size() || t < 0) return;

        if(cand[idx] <= t){
            subset.push_back(cand[idx]);
            f(cand, t-cand[idx], idx, subset);
            subset.pop_back();
        }

        
        f(cand, t, idx+1, subset);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        result.clear();
        vector<int> subset;
        f(candidates, target, 0, subset);
        return result;
    }
};