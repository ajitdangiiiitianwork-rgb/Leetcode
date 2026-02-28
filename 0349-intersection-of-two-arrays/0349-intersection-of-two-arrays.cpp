class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        for(int ele: nums1) m1[ele]++;
        for(int ele : nums2) m2[ele]++;
    
        for(auto& [key, val] : m1){
            if(m2.find(key) != m2.end() && m2[key] > 0) ans.push_back(key);
        }
        return ans;
    }
};