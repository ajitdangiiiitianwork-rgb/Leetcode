class Solution {
public:
    int maximumScoreHelper(int i, int left, int right, vector<int>& nums, vector<int>& multipliers, vector<vector<int>>& dp){
        if(i == multipliers.size()) return 0;
        if(dp[i][left] != -1) return dp[i][left];

        int leftScore =  multipliers[i]*nums[left] + maximumScoreHelper(i+1, left + 1, right, nums, multipliers, dp);
        int rightScore = multipliers[i]*nums[right] + maximumScoreHelper(i+1, left, right-1, nums, multipliers, dp);

        return dp[i][left] = max(leftScore, rightScore);
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return maximumScoreHelper(0, 0, nums.size()-1, nums, multipliers, dp);
    }
};