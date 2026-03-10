class Solution {
public:
    bool isBroken(char ch, string brokenLetters) {
        for (char letter : brokenLetters) {
            if (letter == ch) {
                return true;
            }
        }
        return false;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        int i = 0;
        int count = 0;
        bool check = true;
        int len = text.size();
        while (i < len) {
            char ch = text[i];
            if (ch == ' ') {
                count++;
                i++;
                continue;
            } else if (isBroken(ch, brokenLetters)) {
                check = false;
                while (text[i] != ' ' && i < len) {
                    i++;
                }
            } else {
                check = true;
            }
            i++;
        }
        if (check)
            count++;
        return count;
    }
};