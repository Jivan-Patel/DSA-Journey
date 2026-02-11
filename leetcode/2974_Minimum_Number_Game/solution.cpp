class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int l = nums.size();
        while (i < l) {
            int temp = nums[i];
            nums[i] = nums[i + 1];
            nums[i + 1] = temp;
            i = i + 2;
        }
        return nums;
    }
};