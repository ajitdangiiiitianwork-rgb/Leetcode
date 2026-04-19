class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        long maxLen = 0;
        long i = 0;
        long j = 0;

        while(j < fruits.size()){
            mp[fruits[j]]++;

            while(mp.size() > 2){
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }

            maxLen = max(j-i+1, maxLen);
            j++;
        }
        
        return maxLen;
    }
};