class Solution {
public:
    string truncateSentence(string s, int k) {
        string res = "";
        int word = 0;
        int i = 0;
        int l =s.size();
        while (i < l && word < k) {
            res += s[i];
            i++;
            if (s[i] == ' ')
                word++;
        }
        return res;
    }
};