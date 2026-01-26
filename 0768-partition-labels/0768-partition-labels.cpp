class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOccurence(26, 0);
        for(int i = 0; i < s.size(); i++){
            lastOccurence[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int farthest = 0, start = 0;
        for(int i = 0; i < s.size(); i++){
            farthest = max(farthest, lastOccurence[s[i] - 'a']);
            if(i == farthest){
                ans.push_back(i-start+1);
                start = i+1;
            }
        }
        return ans;
    }
};