class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int low = 0, high = 0, n = nums.size();

        while(high < n && nums[high] != 0) high++;
        int zeroI = high;
        int maxArr = (high == n) ? high - low - 1 : high - low;
        high++;

        while(high < n) {
            while(high < n && nums[high] != 0) high++;
            maxArr = max(maxArr, high - low - 1);
            
            low = zeroI + 1;
            zeroI = high;
            high++;
        }

        return maxArr;
    }
};