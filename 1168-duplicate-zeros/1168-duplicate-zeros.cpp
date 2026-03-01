class Solution {
public:
    void Modify(vector<int>& arr, int idx){
        int n = arr.size();
        int i = n-1;
        while(i != idx){
            arr[i] = arr[i-1];
            i--;
        }
        arr[i] = 0;
    }

    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        while(i < n-1){
            if(arr[i] == 0){
                Modify(arr, i+1);
                i += 2;
            } else i++;
        }
    }
};