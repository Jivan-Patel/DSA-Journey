class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        int res = -1;
        for (int num : arr)
            freq[num]++;
        for (auto& [n, f] : freq) {
            if (n == f) res = max(res, n);
        }
        return res;
    }
};