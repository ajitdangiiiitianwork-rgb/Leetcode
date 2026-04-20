class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int maxLen = 0;
        long sum = 0;
        sort(nums.begin(), nums.end());
        while(j < nums.size()){
            sum += nums[j];
            while((long)nums[j] * (j-i+1) - sum > k){
                sum -= (long)nums[i];
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;

        }

        return maxLen;
    }
};