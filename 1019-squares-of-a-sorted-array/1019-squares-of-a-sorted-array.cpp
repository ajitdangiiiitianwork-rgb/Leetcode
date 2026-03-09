class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int val = 0;
        int l = 0, r = nums.size()-1;
        vector<int> result(nums.size(), 0);
        for(int i = nums.size() - 1; i >= 0; i--){
            if(abs(nums[l]) > abs(nums[r])) {
                val = nums[l];
                l++;
            }
            else {
                val = nums[r];
                r--;
            }
            result[i] = val*val;
        }
        return result;
    }
};