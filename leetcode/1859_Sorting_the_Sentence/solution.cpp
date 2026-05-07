class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(10);
        int i = 1;
        int n = s.size();
        string current;
        while (i < n) {
            while (i < n && s[i] != ' ') {
                current += s[i - 1];
                i++;
            }
            int idx = s[i - 1] - '0';
            words[idx] = current;
            current = "";
            i += 2;
        }
        string res;
        for (string word : words) {
            if (word.size())
                res += word + ' ';
        }
        res.pop_back();
        return res;
    }
};