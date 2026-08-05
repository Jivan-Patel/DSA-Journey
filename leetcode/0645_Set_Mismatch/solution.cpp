class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int missing = 1, repeat = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                repeat = nums[i];
            } else if (nums[i] == missing) {
                missing++;
            }
        }
        return {repeat, missing};
    }
};