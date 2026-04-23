class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int m = nums.size();
        vector<long long> res(m, 0);
        unordered_map<int, vector<int>> check;
        for (int i = 0; i < m; i++) {
            check[nums[i]].push_back(i);
        }
        for (auto& [num, sameIdx] : check) {
            long long rightSum =
                accumulate(sameIdx.begin(), sameIdx.end(), 0LL);
            long long leftSum = 0;
            int n = sameIdx.size();
            for (int i = 0; i < n; i++) {
                int idx = sameIdx[i];
                rightSum -= idx;
                res[idx] = ((long long)idx * i - leftSum) +
                           (rightSum - (long long)idx * (n - i - 1));
                leftSum += idx;
            }
        }
        return res;
    }
};