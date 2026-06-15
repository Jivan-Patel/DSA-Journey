class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans = "";

        int idx = word.find(ch);

        for(int i = idx; i >= 0; i--) {
            ans += word[i];
        }

        for(int i = idx + 1; i < word.size(); i++) {
            ans += word[i];
        }

        return ans;
    }
};