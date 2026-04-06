class Solution {
public:
    void recReverse(vector<char> &s, int i, int j){
        // base case
        if(i < j){
            swap(s[i], s[j]);
            i++;
            j--;
            recReverse(s, i , j);
        }
    }

    void reverseString(vector<char>& s) {
        recReverse(s, 0, s.size()-1);
    }
};