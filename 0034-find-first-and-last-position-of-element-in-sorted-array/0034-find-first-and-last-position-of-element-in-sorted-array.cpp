class Solution {
public:
    int BLS(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1;
        int pos = -1;
        while(low <= high){
            int mid = (high - low)/2 + low;
            if(nums[mid] == target){
                pos = mid;
                high = mid-1;
            }
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return pos;
    }

    int BRS(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1;
        int pos = -1;
        while(low <= high){
            int mid = (high - low)/2 + low;
            if(nums[mid] == target){
                pos = mid;
                low = mid+1;
            }
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return pos;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int leftMost = BLS(nums, target);
        int rightMost = BRS(nums, target);
        return {leftMost, rightMost};
    }
};