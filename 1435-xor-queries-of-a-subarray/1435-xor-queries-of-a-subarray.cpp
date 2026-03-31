class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>result;
        // find prefix XOR of the given array
        for(int i = 1; i < arr.size(); i++){
            arr[i] ^= arr[i-1];
        }

        // Now we can use prefix XOR array arr to calculate XOR from left to right
        // concept : (A xor B) xor A = B
        for(int i = 0; i < queries.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];

            if(left == 0) result.push_back(arr[right]);
            else {
                left = left - 1; // to XOR out the left part which we dont require
                int XOR = arr[right] ^ arr[left];
                result.push_back(XOR);
            }
        }
        return result;
    }
};