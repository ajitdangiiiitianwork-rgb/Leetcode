class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char letter = letters[0];
        for(int i = 0; i < letters.size(); i++){
            if(letters[i] > target){
                letter = letters[i];
                break;
            }
        }
        return letter;
    }
};