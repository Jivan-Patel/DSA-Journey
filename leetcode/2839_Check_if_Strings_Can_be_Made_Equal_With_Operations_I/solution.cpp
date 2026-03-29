class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for (int i = 0; i < s1.size(); i++) {
            if ((s1[i] != s2[i]) &&
                ((i < 2 && (s1[i + 2] != s2[i] || s1[i] != s2[i + 2])) ||
                 (i >= 2 && (s1[i - 2] != s2[i] || s1[i] != s2[i - 2])))) {
                return false;
            }
        }
        return true;
    }
};