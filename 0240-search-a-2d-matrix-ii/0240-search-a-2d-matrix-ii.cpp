class Solution {
public:
    bool binarySearch(vector<int>& arr, int start, int end, int target){
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(arr[mid] == target) return true;

            if(arr[mid] > target) end = mid - 1;
            else start = mid + 1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0; i < n; i++){
            bool flag = binarySearch(matrix[i], 0, m-1, target);
            if(flag) return flag;
        }

        return false;
    }
};