class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = INT_MIN;
        int idx = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= max){
                max = nums[i];
                idx = i;
            }
        }

        for(int num : nums){
            if(num == max) continue;
            if(2*num > max) return -1;
        }

        return idx;
    }
};