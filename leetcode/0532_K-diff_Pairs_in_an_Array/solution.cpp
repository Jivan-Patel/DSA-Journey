class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        set<pair<int, int>> trackedIdx;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int minVal = min(nums[i], nums[j]);
                int maxVal = max(nums[i], nums[j]);
                if (abs(nums[i] - nums[j]) == k &&
                    !trackedIdx.count({minVal, maxVal})) {
                    count++;
                    trackedIdx.insert({minVal, maxVal});
                }
            }
        }

        return count;
    }
};