class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int minNum = INT_MAX, maxNum = INT_MIN;
        for(int n : nums) {
            minNum = min(minNum, n);
            maxNum = max(maxNum, n);
        }
        long long ans = 1LL * (maxNum - minNum);

        return ans * k;
    }
};