class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;
        int len = s.size();
        
        for (int i = 0; i < len; i++) {
            res += ('z' + 1 - s[i]) * (i + 1);
        }
        return res;
    }
};