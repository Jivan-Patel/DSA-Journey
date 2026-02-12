class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;
        int len = s.size();
        for (int i = 0; i < len; i++)
            res += (123 - (int)s[i]) * (i + 1);
        return res;
    }
};