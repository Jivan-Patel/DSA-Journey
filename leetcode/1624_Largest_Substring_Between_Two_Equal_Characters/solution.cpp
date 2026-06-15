class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int longestSubStr = -1;

        for(int i = 0; i < s.size(); i++) {
            int j = s.size() - 1;

            while(s[j] != s[i]) j--;

            longestSubStr = max(longestSubStr, j - i - 1);
        }

        return longestSubStr;
    }
};