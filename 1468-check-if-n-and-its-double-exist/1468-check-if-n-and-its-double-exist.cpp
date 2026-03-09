class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<float> s;
        s.insert((float)arr[0]);
        for(int i = 1; i < arr.size(); i++){
            float x = arr[i];
            if(s.count(x/2) || s.count(x*2)) return true;
            else s.insert(x);
        }
        return false;
    }
};