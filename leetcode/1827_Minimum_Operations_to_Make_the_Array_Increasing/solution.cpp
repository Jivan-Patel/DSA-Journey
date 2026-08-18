class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operation = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] >= nums[i]) {
                operation += nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1] + 1;
            }
        }
        return operation;        
    }
};