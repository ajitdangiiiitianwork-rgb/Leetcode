class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& nums, int idx){
        // Base case
        if(idx == nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int j = idx; j < nums.size(); j++){
            swap(nums[idx], nums[j]);
            helper(res, nums, idx + 1);
            swap(nums[idx], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res,nums, 0);
        return res;
    }
};