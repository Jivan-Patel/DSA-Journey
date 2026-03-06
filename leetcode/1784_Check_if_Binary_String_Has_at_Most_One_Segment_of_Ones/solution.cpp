class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = s.size() - 1;
        bool flag = false;
        while (i > 0) {
            if (!flag && s[i] == '1')
                flag = true;
            if (flag && s[i] == '0')
                return false;
            i--;
        }
        return true;
    }
};