class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = INT_MIN;
        int maxRange = 0;
        int currRange = 0;


        // Concept : A & B -> gives a number between 0...min(A,B)
        // Using this we can infer that if there is only one max then only one size array otherwise the 
        // maximum time a maxValue is occuring consecutively
        for(int i = 0; i < nums.size(); i++){
            if(maxVal < nums[i]){
                maxVal = nums[i];
                currRange = 1;
                maxRange = 1;
            }

            else if(maxVal == nums[i]){
                currRange += 1;
            }

            else currRange = 0;
            maxRange = max(maxRange, currRange);
        }

        return maxRange;
    }
};