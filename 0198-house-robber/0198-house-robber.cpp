class Solution {
public:
    int helper(int i, vector<int>& nums, vector<int>& dp){
        if(i == 0) return nums[0];
        if(i == 1) return max(nums[0], nums[1]);
        if(dp[i] != -1) return dp[i];

        dp[i] = max(helper(i-1, nums, dp), nums[i] + helper(i-2, nums, dp));
        return dp[i];
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return helper(nums.size() - 1, nums, dp);
    }
};