class Solution {
public:
    string removeOuterParentheses(string s) {
        int openingBracket = 0;
        string res = "";

        for (char ch : s) {
            if (ch == '(') {
                if (openingBracket != 0) res += ch;
                openingBracket++;
            }
            else {
                openingBracket--;
                if (openingBracket != 0) res += ch;
            }
        }
        return res;
    }
};