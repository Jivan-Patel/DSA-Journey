class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        bool isSorted = is_sorted(nums.begin(), nums.end());
        int operations = 0;

        while (isSorted != true) {
            pair<int, int> minSum = {-1, INT_MAX};
            for (int i = 0; i < nums.size() - 1; i++) {
                if (minSum.second > nums[i] + nums[i + 1]) {
                    minSum.first = i;
                    minSum.second = nums[i] + nums[i + 1];
                }
            }
            nums[minSum.first] = minSum.second;
            nums.erase(nums.begin() + minSum.first + 1);

            isSorted = is_sorted(nums.begin(), nums.end());
            operations++;
        }

        return operations;
    }
};