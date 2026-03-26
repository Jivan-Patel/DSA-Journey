class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSubSum = nums[0];
        int currentSum = 0;
        for (int i = 0; i < n; i++) {
            currentSum += nums[i];
            maxSubSum = max(currentSum, maxSubSum);
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        return maxSubSum;
    }
};