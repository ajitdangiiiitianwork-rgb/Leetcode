class Solution {
public:
    string shortestPalindrome(string s) {
        // using FH and RH
        // steps
        // 1. Calculate FH and RH
        //    i. whenever they are equal put PIdx at that index
        // After looping reverse the string after Pidx and attach it to starting and return the answer

        long modulo = (long)(pow(10,9)) + 7;
        long fh = 0;
        long rh = 0;

        long power = 1;
        long base = 26;
        int Pidx = -1;
        for(int i = 0; i < s.size(); i++){
            fh = (fh * base + (s[i] - 'a' + 1)) % modulo;
            rh = ((s[i] - 'a' + 1) * power + rh) % modulo;

            if(fh == rh){
                Pidx = i;
            }

            power = (power * base) % modulo; // 26 is the base value;
        }

        string rev = s.substr(Pidx + 1);
        reverse(rev.begin(), rev.end());
        return rev + s;
    }
};