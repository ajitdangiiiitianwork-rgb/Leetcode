class Solution {
public:
    int calcNextMove(vector<int>& nums, int curr){
        int n = nums.size();
        return ((curr + nums[curr]) % n + n) % n; // safe modulo
    }

    bool circularArrayLoop(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) continue;
            int slow = i;
            int fast = i;
            bool isPos = nums[i] > 0 ? true : false;
            do{
                slow = calcNextMove(nums, slow);
                if((nums[slow] > 0) != isPos) break;

                fast = calcNextMove(nums, fast);
                if((nums[fast] > 0) != isPos) break;
                
                fast = calcNextMove(nums, fast);
                if((nums[fast] > 0) != isPos) break;

                if(slow == fast){
                    if(slow != calcNextMove(nums, slow)) return true;
                    break;
                }
                

            } while(slow != fast);

            int curr = i;
            while(nums[curr] > 0){
                int next = calcNextMove(nums, curr);
                nums[curr] = 0;
                curr = next;
                if(nums[curr] == 0) break;
            }

            while(nums[curr] < 0){
                int next = calcNextMove(nums, curr);
                nums[curr] = 0;
                curr = next;
                if(nums[curr] == 0) break;
            }
        }
        return false;
    }
};