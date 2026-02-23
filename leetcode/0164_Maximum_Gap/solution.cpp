class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxDiff = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] - nums[i] > maxDiff)
                maxDiff = nums[i + 1] - nums[i];
        }
        return maxDiff;
    }
};