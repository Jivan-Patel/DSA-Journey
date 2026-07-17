class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int low = 0, high = 0;
        unordered_set<int> currentWindow;
        long long currentSum = 0, maxSum = 0;

        while(high < nums.size()) {
            while(currentWindow.count(nums[high])) {
                currentWindow.erase(nums[low]);
                currentSum -= nums[low++];
            }

            currentWindow.insert(nums[high]);
            currentSum += nums[high];
            
            while(high - low + 1 > k) {
                currentWindow.erase(nums[low]);
                currentSum -= nums[low++];
            }

            if(high - low + 1 == k) maxSum = max(maxSum, currentSum);

            high++;
        }

        return maxSum;
    }
};