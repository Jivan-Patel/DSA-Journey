class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxLen = 0;

        for (int n : nums) freq[n]++;

        for (auto& p : freq) {
            if (freq.count(p.first - 1)) {
                maxLen = max(maxLen, freq[p.first - 1] + p.second);
            }
        }

        return maxLen;
    }
};