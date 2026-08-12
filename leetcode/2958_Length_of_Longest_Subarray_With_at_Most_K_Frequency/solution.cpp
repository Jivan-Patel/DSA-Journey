class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> track;
        int low = 0, high = 0, maxLen = 0;

        while(high < nums.size()) {
            track[nums[high]]++;

            if(track[nums[high]] > k) {
                while(nums[low] != nums[high]) {
                    track[nums[low++]]--;
                }
                track[nums[low++]]--;
            }

            maxLen = max(maxLen, high - low + 1);
            high++;
        }
        
        return maxLen;
    }
};