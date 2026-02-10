class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        int l = nums.size();
        for (int i = 0; i < l - 2; i++) {
            for (int j = i + 1; j < l - 1; j++) {
                for (int k = j + 1; k <l; k++) {
                    if (nums[j] - nums[i] == diff && nums[k] - nums[j] == diff)
                        count++;
                }
            }
        }
        return count;
    }
};