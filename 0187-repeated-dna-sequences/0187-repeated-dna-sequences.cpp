class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10) return {};
        // using two sets seen and result
        unordered_set<string> seen;
        unordered_set<string> result;

        for(int i = 0; i <= s.size() - 10; i++){
            string sub = s.substr(i, 10);
            if(seen.find(sub) != seen.end()) result.insert(sub);
            else seen.insert(sub);
        
        }

        return vector<string>(result.begin(), result.end());
    }
};