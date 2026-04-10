class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxSum = 0, minSum = 0;
        int lastI = nums.size() - 1;
        for(int i = 0; i < k; i++) {
            minSum += nums[i];
            maxSum += nums[lastI - i];
        }
        return abs(minSum - maxSum);
    }
};