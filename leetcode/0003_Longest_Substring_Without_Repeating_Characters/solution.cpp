class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0, high = 0;
        int maxLen = 0;
        vector<bool> track(256, false);

        while (high < s.size()) {
            if (track[s[high]]) {
                while (low < high && s[low] != s[high]) {
                    track[s[low]] = false;
                    low++;
                }
                track[s[low]] = false;
                low++;
            }
            track[s[high]] = true;
            maxLen = max(maxLen, high - low + 1);
            high++;
        }
        return maxLen;
    }
};