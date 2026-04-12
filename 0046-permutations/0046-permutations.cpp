class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& ans, vector<int> nums, int n){
        // Base case
        if(ans.size() == n){
            res.push_back(ans);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            ans.push_back(nums[i]);
            vector<int> temp = nums;
            temp.erase(temp.begin() + i);
            helper(res, ans, temp, n);
            ans.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        helper(res, ans, nums, nums.size());
        return res;
    }
};