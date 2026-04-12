class Solution {
public:
    void helper(vector<string>& res, unordered_map<int, vector<char> > &mp, string &digits, string& s, int index){
        if(index == digits.size()){
            // base case
            res.push_back(s);
            return;
        }

        char c = digits[index];
        for(char d : mp[c - '0']){
            s.push_back(d);
            helper(res, mp, digits, s, index+1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<char> > mp;
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};

        vector<string> res;
        string s;
        helper(res, mp, digits, s, 0);
        return res;
    }
};