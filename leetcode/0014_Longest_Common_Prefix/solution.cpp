class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int longestPrefix = strs[0].size();
        int i = 1;
        while (i < strs.size() && longestPrefix > 0) {
            int currentPrefix = 0;
            int j = 0;
            while(j < longestPrefix && strs[i][j] ==  strs[i-1][j]) {
                currentPrefix++;
                j++;
            }
            longestPrefix = min(longestPrefix, currentPrefix);
            i++;
        }
        string res;
        for(int i = 0; i < longestPrefix; i++) {
            res += strs[0][i];
        }
        return res;
    }
};