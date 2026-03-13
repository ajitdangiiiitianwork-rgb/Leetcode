class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // Just traverse from back and maintain a max variable
        int i = arr.size() - 1;
        int max = arr[i];
        arr[i] = -1;  
        i--;
        while(i >= 0){
            int curr = arr[i];
            arr[i] = max;
            if(curr > max) max = curr;
            i--;
        }
        return arr;
    }
};