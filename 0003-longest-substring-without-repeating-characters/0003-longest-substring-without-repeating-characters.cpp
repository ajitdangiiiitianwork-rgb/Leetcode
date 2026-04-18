class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        long maxLen = 0;
        long i = 0;
        unordered_set<char> st;
        for(long j = 0; j < s.size(); j++){
            while(st.find(s[j]) != st.end()){
                // until we keep finding the character in the window we continously remove characters
                st.erase(s[i]);
                i++;
            }

            st.insert(s[j]);
            maxLen = max(j-i+1, maxLen);
        }

        return maxLen;
    }
};