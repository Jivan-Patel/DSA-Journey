class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int len = nums.size();
        int minDiff = len;
        for(int i = 0; i < len; i++) {
            if(nums[i] != 1) continue;
            for(int j = 0; j < len; j++) {
                if(i != j && nums[j] == 2) {
                    minDiff = min(minDiff, abs(i-j));                    
                }
            }
        }
        return minDiff != len ? minDiff : -1;
    }
};