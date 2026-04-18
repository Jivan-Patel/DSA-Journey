class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prefix = 0;
        long long sum = 0;
        int i = nums.size() - 1;
        while (i >= 0 && sum + nums[i] > 0) {
            sum += nums[i];
            prefix++;
            i--;
        }
        return prefix;
    }
};