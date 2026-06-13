class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int n : nums) freq[n]++;

        int maxF = 0;

        for(auto &n : freq) {
            maxF = max(maxF, n.second);
        }

        vector<vector<int>> res(maxF);

        for(auto &[n , f] : freq) {
            for(int i = 0; i < f; i++) {
                res[i].push_back(n);
            }
        }

        return res;
    }
};