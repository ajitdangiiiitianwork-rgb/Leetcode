class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s;
        for(char c : allowed) s.insert(c);
        int count = 0;
        for(string word : words){
            bool flag = true;
            for(int i = 0; i < word.size(); i++){
                if(s.find(word[i]) == s.end()){
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }

        return count;
    }
};