class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i = 0;
        unordered_set<int> s;
        for(int j = 0; j < nums.size(); j++){
            if(s.find(nums[j]) !=s.end()){
                // duplicate found
                return true;
            }

            s.insert(nums[j]);
            if(j-i >= k){
                s.erase(nums[i]);
                i++;
            } 
        }

        return false;
    }
};