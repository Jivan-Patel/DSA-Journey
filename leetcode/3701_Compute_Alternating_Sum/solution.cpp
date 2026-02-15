class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
            result += (i % 2 == 0) ? nums[i] : -nums[i];
        return result;
    }
};