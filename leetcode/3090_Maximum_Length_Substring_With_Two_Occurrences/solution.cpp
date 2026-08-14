class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26, 0);
        int high = 0, low = 0, maxLen = 0;

        while (high < s.size()) {
            freq[s[high] - 'a']++;

            if (freq[s[high] - 'a'] > 2) {
                while (s[high] != s[low]) {
                    freq[s[low++] - 'a']--;
                }
                freq[s[low++] - 'a']--;
            }

            maxLen = max(maxLen, high - low + 1);
            high++;
        }

        return maxLen;
    }
};