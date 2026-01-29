class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int low, int high){
        while(low <= high){
            int mid = (high - low)/2 + low;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int loc = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                loc = i;
                break;
            }
        }

        int idx1 = binarySearch(nums, target, 0, loc-1);
        int idx2 = binarySearch(nums, target, loc, nums.size()-1);

        if(idx1 != -1) return idx1;
        if(idx2 != -1) return idx2;
        return -1;
    }
};