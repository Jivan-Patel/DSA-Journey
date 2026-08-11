class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int maxSum = nums[0];
        int i = 1, n = nums.size();
        unordered_set<int> track(nums.begin(), nums.end());

        while(i < n && nums[i] == nums[i-1] + 1) {
            maxSum += nums[i];
            i++;
        }

        while(track.count(maxSum)) {
            maxSum++;
        }

        return maxSum;
    }
};