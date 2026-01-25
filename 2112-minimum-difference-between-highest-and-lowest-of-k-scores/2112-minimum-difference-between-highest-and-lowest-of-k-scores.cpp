class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1) return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for(int i = nums.size()-1; i >= k-1; i--){
            int diff = nums[i] - nums[i-k+1];
            if(diff < ans) ans = diff;
        }
        return ans;
    }
};