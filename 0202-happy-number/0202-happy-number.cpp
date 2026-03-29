class Solution {
public:
    int squareOfDigits(int n){
        int sum = 0;
        while(n != 0){
            sum += pow((n%10), 2);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = squareOfDigits(slow);
        while(fast != slow){
            slow = squareOfDigits(slow);
            fast = squareOfDigits(squareOfDigits(fast));
            if(fast == 1) return true; 
        }

        return slow == 1;
    }
};