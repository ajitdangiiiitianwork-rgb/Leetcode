class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long firstMax = LONG_MIN;
        long secMax = LONG_MIN;
        long thirdMax = LONG_MIN;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == firstMax || nums[i] == secMax || nums[i] == thirdMax) continue;
            if(nums[i] > firstMax){
                thirdMax = secMax;
                secMax = firstMax;
                firstMax = nums[i];
            } else if (nums[i] > secMax){
                thirdMax = secMax;
                secMax = nums[i];
            } else if (nums[i] > thirdMax) {
                thirdMax = nums[i];
            }
        }

        return thirdMax == LONG_MIN? firstMax : thirdMax;
    }
};