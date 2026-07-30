class Solution {
public:
    string compressedString(string word) {
        string res = "";
        int i = 0;
        while (i < word.size()) {
            int count = 0;
            char ch = word[i];
            while (i < word.size() && word[i] == ch && count < 9) {
                i++;
                count++;
            }
            res += to_string(count) + ch;
        }
        return res;
    }
};