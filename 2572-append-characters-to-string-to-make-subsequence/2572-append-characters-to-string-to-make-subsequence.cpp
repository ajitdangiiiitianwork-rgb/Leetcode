class Solution {
public:
    int appendCharacters(string s, string t) {
        int SP = 0; // s string pointer
        int TP = 0; // t string pointer

        int n = s.size(), m = t.size();
        while(SP < n && TP < m){
            if(s[SP] != t[TP]){
                SP++;
            } else {
                SP++;
                TP++;
            }
        }

        if(TP == m) return 0;
        return m - TP;
    }
};