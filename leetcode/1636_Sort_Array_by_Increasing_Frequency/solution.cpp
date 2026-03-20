class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> freq;
        vector<vector<int>> freqArr;
        for (int num : nums) {
            if (freq[num]) {
                freq[num]++;
            } else {
                freq[num] = 1;
            }
        }
        for (auto& [num, frequency] : freq) {
            vector<int> frequ = {num, frequency};
            freqArr.push_back(frequ);
        }
        for (int i = 0; i < freqArr.size(); i++) {
            for (int j = i + 1; j < freqArr.size(); j++) {
                if (freqArr[i][1] > freqArr[j][1] ||
                    (freqArr[i][1] == freqArr[j][1] &&
                     freqArr[i][0] < freqArr[j][0])) {
                    vector<int> temp = freqArr[i];
                    freqArr[i] = freqArr[j];
                    freqArr[j] = temp;
                }
            }
        }
        vector<int> res;
        for (auto num : freqArr) {
            for (int i = 0; i < num[1]; i++) {
                res.push_back(num[0]);
            }
        }
        return res;
    }
};