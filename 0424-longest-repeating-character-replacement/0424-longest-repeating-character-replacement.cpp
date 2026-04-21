class Solution {
public:
    int characterReplacement(string s, int k) {
        long maxLen = 0;
        long maxC = 0;
        vector<long> freq(26, 0);
        long i = 0, j = 0;
        
        while(j < s.size()){
            if(maxLen > s.size() - i) break;
            char c = s[j];
            freq[c - 'A']++;
            maxC = max(maxC, freq[c - 'A']);

            while((j-i+1) - maxC > k){
                char d = s[i];
                freq[d - 'A']--;
                i++;

                for(int l = 0; l < 26; l++){
                    if(freq[l] > maxC) maxC = freq[l];
                }
            }

            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};