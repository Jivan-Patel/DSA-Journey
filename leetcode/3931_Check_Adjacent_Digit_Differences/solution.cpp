class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size() - 1;

        for (int i = 0; i < n; i++) {
            if (abs(s[i] - s[i + 1]) > 2) return false;
        }
        return true;
    }
};