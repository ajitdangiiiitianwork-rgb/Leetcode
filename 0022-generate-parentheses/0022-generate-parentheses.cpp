class Solution {
public:
    void helper(vector<string>& res, int n, int no_of_open, int no_of_close, string s){
        if(no_of_open == n && no_of_close == n) {
            // base case
            res.push_back(s);
            return;
        }

        if(no_of_open < n) helper(res, n, no_of_open + 1, no_of_close, s + '('); 
        if(no_of_close < no_of_open) helper(res, n, no_of_open, no_of_close + 1, s + ')');

    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, n, 0, 0, "");
        return res;
    }
};