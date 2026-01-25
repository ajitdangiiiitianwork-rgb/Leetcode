class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;
        for(char c: s) freq[c]++;
        int maxLen = 0;
        bool hasOdd = false;
        for(auto&[c, count]: freq){
            if(count % 2 != 0){
                maxLen += count-1;
                hasOdd = true;
            }
            else maxLen += count;
        }

        if(hasOdd) maxLen += 1;
        return maxLen;
    }
};