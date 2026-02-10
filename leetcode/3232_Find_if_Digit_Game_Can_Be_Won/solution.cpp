class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleSum = 0;
        int multiSum = 0;
        int l = nums.size();
        for (int i = 0; i < l; i++) {
            (nums[i] < 10) ? singleSum += nums[i] : multiSum += nums[i];
        }
        return singleSum != multiSum;
    }
};