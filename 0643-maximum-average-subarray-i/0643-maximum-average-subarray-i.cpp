class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        long long sum = 0;
        long long maxSum = INT_MIN;

        for(i; i < k; i++){
            sum += nums[i];
        }

        maxSum = sum;

        for(i = k; i < nums.size(); i++){
            sum = sum + nums[i] - nums[i-k];
            if(sum > maxSum) maxSum = sum;
        }

        return (double)maxSum/k;
    }
};