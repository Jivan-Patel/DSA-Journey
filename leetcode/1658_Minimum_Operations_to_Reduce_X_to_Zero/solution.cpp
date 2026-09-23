class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());

        int minLen = n + 1;
        int i = 0, j = 0, sum = 0;

        while (j < 2 * n) {
            while (j < 2 * n && sum < x) {
                sum += nums[j++];
            }
            if (sum == x) {
                if (j - i <= n && (i == 0 || j == n || (i < n && j > n))) {
                    minLen = min(minLen, j - i);
                }
                sum -= nums[i++];
            }
            while (i < j && sum > x) {
                sum -= nums[i++];
            }
        }

        return minLen == n + 1 ? -1 : minLen;
    }
};