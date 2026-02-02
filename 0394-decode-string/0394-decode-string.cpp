class Solution {
public:
    string decodeString(string s) {
        string ans;
        stack<int> sI;
        stack<string> str;
        int num = 0;
        for(char c: s){
            if(isdigit(c)){
                num = num * 10 + (c - '0');
            } else if(c == '['){
                sI.push(num);
                str.push(ans);
                num = 0;
                ans = "";
            } else if(c == ']'){
                int rep = sI.top(); sI.pop();
                string prev = str.top(); str.pop();
                string extends = "";
                for(int i = 0; i < rep; i++){
                    extends += ans;
                }
                ans = prev + extends;
            } else {
                ans += c;
            }
        }
        return ans;
    }
};