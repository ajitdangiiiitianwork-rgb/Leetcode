class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> m;
        vector<string> result;
        
        int i = 0;
        while(i < s1.size()){
            string s = "";
            int j = i;
            while(j < s1.size() && s1[j] != ' '){
                s += s1[j];
                j++;
            }

            m[s] += 1;
            i = j+1;
        }

        i = 0;
        while(i < s2.size()){
            string s = "";
            int j = i;
            while(j < s2.size() && s2[j] != ' '){
                s += s2[j];
                j++;
            }

            m[s] += 1;
            i = j+1;
        }

        for(auto& key: m){
            if(key.second == 1) result.push_back(key.first);
        }

        return result;
    }
};