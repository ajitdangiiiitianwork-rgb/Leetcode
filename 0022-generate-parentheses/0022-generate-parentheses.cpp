class Solution {
public:
    bool isValidParentheses(vector<char>& str){
        int count = 0;
        for(char c: str){
            if(c == '(') count++;
            else count--;

            if(count < 0) return false;
        }

        return count == 0;
    }

    void helper(vector<char>& str, vector<string>& res, int n){
        if(str.size() == 2*n){
            // base case 
            // check for validity and then add to res

            if(isValidParentheses(str)){
                string s = "";
                for(char c: str) s += c;
                res.push_back(s);
            }
            return;            
        }

        str.push_back('(');
        helper(str, res, n);
        str.pop_back();
        str.push_back(')');
        helper(str, res, n);
        str.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<char> str;
        helper(str, res, n);
        return res;
    }
};