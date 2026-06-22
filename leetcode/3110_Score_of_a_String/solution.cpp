class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        int len = s.size();
        for (int i = 0; i < len - 1; i++) {
            int a = s[i];
            int b = s[i + 1];
            sum += (a > b) ? a - b : b - a;
        }
        return sum;
    }
};