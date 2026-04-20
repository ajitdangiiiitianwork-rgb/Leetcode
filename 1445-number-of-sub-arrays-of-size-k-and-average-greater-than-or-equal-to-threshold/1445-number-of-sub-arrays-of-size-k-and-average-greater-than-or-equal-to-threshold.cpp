class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int th) {
        int counter = 0;
        int i = 0;
        int sum = 0;
        for(i = 0; i < k; i++) sum += nums[i];

        if(sum/k >= th) counter++;

        for(i = k; i < nums.size(); i++){
            sum -= nums[i-k];
            sum += nums[i];
            if(sum/k >= th) counter++;
        }

        return counter;
    }
};