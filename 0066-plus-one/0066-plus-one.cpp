class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int carry = 0;
        vector<int> result;
        int n = nums.size();
        for(int i = n-1; i >= 0; i--){
            int sum;
            if(i == n-1){
                sum = nums[i] + 1;
                if(sum >= 10){
                    carry = 1;
                }
            } else {
                sum = nums[i] + carry;
                if(sum < 10) carry = 0;
                else if(sum >= 10) carry = 1;
            }
            result.push_back(sum%10);
        }

        if(carry) result.push_back(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};