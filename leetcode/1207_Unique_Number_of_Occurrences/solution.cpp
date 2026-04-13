class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) freq[num]++;

        unordered_set<int> freqOfFreq;
        for (auto& [num, frequency] : freq) {
            if(freqOfFreq.find(frequency) != freqOfFreq.end()) return false;
            freqOfFreq.insert(frequency);
        }
        
        return true;
    }
};