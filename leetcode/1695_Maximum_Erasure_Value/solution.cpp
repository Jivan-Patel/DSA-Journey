class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set <int> track;
        int low = 0, high = 0, curSum = 0, maxSum = 0;
        while(high < nums.size()) {
            if(!track.count(nums[high])) {
                track.insert(nums[high]);
                curSum += nums[high];
            }
            else {
                while(nums[low] != nums[high]) {
                    curSum -= nums[low];
                    track.erase(nums[low++]);
                }
                low++;
            } 
            maxSum = max(maxSum, curSum);
            high++;
        }
        return maxSum;
    }
};