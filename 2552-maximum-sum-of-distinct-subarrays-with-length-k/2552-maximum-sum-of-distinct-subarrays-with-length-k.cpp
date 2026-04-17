class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long sum = 0, maxSum = 0;
        int d = 0;
        int n =nums.size();

        int i = 0, j = 0;
        for(j = 0; j < k; j++){
            if(mp[nums[j]] > 0){
                // found the element in map
                d++;
            }
            sum += nums[j];
            mp[nums[j]]++;
        }

        if(d == 0) maxSum = sum;

        for(j; j < n; j++){
            sum -= nums[i];
            if(mp[nums[i]] > 1) d--;
            mp[nums[i]]--;
            i++;
            if(mp[nums[j]] > 0){
                // found the element in map
                d++;
            }

            sum += nums[j];
            mp[nums[j]]++;
            if(d == 0) maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};