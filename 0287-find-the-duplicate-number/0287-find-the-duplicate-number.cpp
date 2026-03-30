class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int correctIdx = 0;
        int i = 0;
        while(i < nums.size()){
            correctIdx = nums[i];
            if(nums[correctIdx] == nums[i]) return nums[i];
            else swap(nums[i], nums[correctIdx]);
        }

        return 10;
    }
};