class Solution {
public:
    bool isEven(int& d){
        int dig = 0;
        while(d != 0){
            dig++;
            d /= 10;
        }
        return dig%2 == 0;
    }

    int findNumbers(vector<int>& nums) {
        int evenNumbers = 0;
        for(int i = 0; i < nums.size(); i++){
            if(isEven(nums[i])) evenNumbers++;
        }

        return evenNumbers;
    }
};