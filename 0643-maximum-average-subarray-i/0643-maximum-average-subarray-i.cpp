class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int sum = 0, maxSum = INT_MIN;
        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            if(j - i + 1 == k){
                maxSum = max(sum, maxSum);
                sum -= nums[i];
                i++;
            }
        }

        double avg = double(maxSum)/k;
        return avg;
    }
};