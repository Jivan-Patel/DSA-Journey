class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        vector<string> wordStore;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') temp += s[i];
            else if (!temp.empty()) {
                wordStore.push_back(temp);
                temp = "";
            }
        }
        if (!temp.empty()) {
            wordStore.push_back(temp);
        }
        temp = "";
        for (int i = wordStore.size() - 1; i >= 0; i--) {
            temp += wordStore[i];
            if (i > 0) temp += ' ';
        }
        return temp;
    }
};