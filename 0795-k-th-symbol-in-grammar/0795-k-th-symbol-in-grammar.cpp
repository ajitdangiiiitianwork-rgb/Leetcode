class Solution {
public:
    int kthGrammar(int n, int k) {
       int flips = 0;
       while(n > 1){
        if(k%2 != 0) k = k/2 + 1;
        else {
            k /= 2;
            flips++;
        }
        n--;
       } 
    if(flips%2 == 0) return 0;
    else return 1;
    }
};