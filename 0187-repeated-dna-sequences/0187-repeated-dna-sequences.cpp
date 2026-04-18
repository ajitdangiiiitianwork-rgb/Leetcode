class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10) return {};
        vector<string> ans;

        unordered_map<string, int> mp;
        string str;
        int i;
        for(i = 0; i < 10; i++){
            str.push_back(s[i]);
        }

        mp[str]++;
        // Now i points to index 10 which means 11th character
        for(i = 10; i < s.size(); i++){
            str.erase(0,1);
            str.push_back(s[i]);
            mp[str]++;
        }

        for(auto& [key, value] : mp){
            if(value > 1) ans.push_back(key);
        }

        return ans;
    }
};