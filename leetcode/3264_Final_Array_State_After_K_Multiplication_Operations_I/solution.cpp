class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int> res;
        int operation = 0;
        while (operation != k) {
            int minI = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[minI] > nums[i])
                    minI = i;
            }
            nums[minI] *= multiplier;
            operation++;
        }
        return nums;
    }
};