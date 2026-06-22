class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count1 = 0;
        string res;
        for (char ch : s) {
            if (ch == '1')
                count1++;
        }
        for (int i = 1; i < count1; i++) {
            res += "1";
        }
        for (int i = 0; i < s.size() - count1; i++) {
            res += "0";
        }
        res += "1";
        return res;
    }
};