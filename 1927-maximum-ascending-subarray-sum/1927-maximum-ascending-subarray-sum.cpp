class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size() == 1) return nums[0]; 
        int maxSum = nums[0];
        int sum = nums[0];
        for(int j = 1; j < nums.size(); j++){
            if(nums[j] > nums[j-1]) sum += nums[j];
            else sum = nums[j];

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};