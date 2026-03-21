class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string res;
            for (int i = 0; i < s.size() - 1; i++) {
                int numI = stoi(string(1, s[i]));
                int numJ = stoi(string(1, s[i + 1]));
                res += to_string((numI + numJ) % 10);
            }
            s = res;
        }
        return s[0] == s[1];
    }
};