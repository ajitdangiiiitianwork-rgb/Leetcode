class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = INT_MIN;
        for(int num : nums){
            if(maxVal < num) maxVal = num;
        }

        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] += nums[i];
        }

        vector<int> dp(maxVal + 1, -1);
        dp[0] = 0;
        dp[1] = mp.count(1) ? mp[1] : 0;

        for(int i = 2; i < dp.size(); i++){
            dp[i] = max(mp[i] + dp[i-2], dp[i-1]);
        }

        return dp[maxVal];
    }
};