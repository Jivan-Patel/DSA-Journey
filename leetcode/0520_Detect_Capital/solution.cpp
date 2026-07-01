class Solution {
public:
    bool detectCapitalUse(string word) {

        string check = "";
        for(char c : word) check += toupper(c);

        if(check == word) return true;

        for(int i = 1; i < word.size(); i++) {
            if(isupper(word[i])) return false;
        }
        
        return true;
    }
};