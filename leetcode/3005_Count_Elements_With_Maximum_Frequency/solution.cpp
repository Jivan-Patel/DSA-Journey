class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> freq;
        int maxF = 1;
        int maxFreqCount = 0;
        for (int num : nums) {
            if (freq[num]) {
                freq[num]++;
                maxF = max(maxF, freq[num]);
            } else {
                freq[num] = 1;
            }
        }
        for (auto& [num, frequency] : freq)
            if (frequency == maxF)
                maxFreqCount += frequency;

        return maxFreqCount;
    }
};