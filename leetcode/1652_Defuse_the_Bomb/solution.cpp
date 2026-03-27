class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res;
        int len = code.size();
        for (int i = 0; i < len; i++) {
            int currentNum = 0;
            for (int j = 1; j <= k; j++) {
                int resI = i + j < len ? i + j : i + j - len;
                currentNum += code[resI];
            }
            for (int j = k; j < 0; j++) {
                int resI = i + j;
                if (resI < 0) {
                    resI += len;
                }
                currentNum += code[resI];
            }
            res.push_back(currentNum);
        }
        return res;
    }
};