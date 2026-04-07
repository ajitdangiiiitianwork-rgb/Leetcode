class Solution {
public:
    double myPowHelper(double x, int n){
        if(n == 0) return 1.0;
        if(n == 1) return x;
        double half = myPowHelper(x, n/2);
        if(n%2 == 0) return half * half;
        return x * half * half;
    }

    double myPow(double x, int n) {
        long long N = n;
        
        if(n < 0) {
            x = 1.0/x;
            N = -N;
        }
        return myPowHelper(x, N);
    }
};