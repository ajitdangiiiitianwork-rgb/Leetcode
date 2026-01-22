class Solution {
public:
    bool sortedArray(vector<int>& nums,int n){
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int counter = 0, n = nums.size();
        while(!sortedArray(nums, n)){
            counter += 1;
            int minPair = INT_MAX, pos = -1;
            for(int i = 1; i < n; i++){
                if(nums[i] + nums[i-1] < minPair){
                    minPair = nums[i] + nums[i-1];
                    pos = i;
                }
            }
            nums[pos-1] = nums[pos] + nums[pos-1];
            for(int i = pos; i < n-1; i++) nums[i] = nums[i+1];
            n = n-1;
        }
        return counter;
    }
};