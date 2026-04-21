class Solution {
public:
    int characterReplacement(string s, int k) {
        long maxLen = 0;
        for(long i = 0; i < s.size(); i++){
            if(maxLen > s.size() - i) break;
            long maxC = 0;
            vector<long> freq(26, 0);

            for(long j = i; j < s.size(); j++){
                char c = s[j];
                freq[c - 'A']++;

                maxC = max(maxC, freq[c - 'A']);

                if((j-i+1) - maxC > k) break;
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};