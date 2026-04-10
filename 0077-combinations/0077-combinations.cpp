class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& ans, int f, int n, int k){
        // base condition
        if(k == ans.size()){
            res.push_back(ans);
            return;
        }

        for(int i = f; i <= n; i++){
            ans.push_back(i);
            backtrack(res, ans, i+1, n, k);
            ans.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> ans;

        backtrack(res, ans, 1, n, k);
        return res;
    }
};