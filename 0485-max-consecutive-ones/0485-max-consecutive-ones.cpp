class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum = 0, maxSum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                sum += nums[i];
                maxSum = max(sum, maxSum);
            } else sum = 0;
        }
        return maxSum;
    }
};