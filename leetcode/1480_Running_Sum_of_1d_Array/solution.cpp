class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int currentSum = 0;
        vector<int> result;
        for (int num : nums) {
            currentSum += num;
            result.push_back(currentSum);
        }
        return result;
    }
};