class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        long long sum = 0;
        long long maxSum = 0;
        int i = 0, n = nums.size();

        for(int j = 0; j < n; j++){
            while(s.find(nums[j]) != s.end()){
                sum -= nums[i];
                s.erase(nums[i]);
                i++;
            }

            sum += nums[j];
            s.insert(nums[j]);

            if(j - i + 1 == k){
                maxSum = max(maxSum, sum);
                sum -= nums[i];
                s.erase(nums[i]);
                i++;
            }
        }

        return maxSum;
    }
};