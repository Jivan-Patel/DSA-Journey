class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k == 1) {
            sort(nums.begin(), nums.end());
            if(nums[nums.size() - 1] != nums[nums.size() - 2]) {
                return nums[nums.size() - 1];
            }
            for(int i = nums.size() - 2; i > 0; i--) {
                if(nums[i] != nums[i-1] && nums[i] != nums[i+1]) {
                    return nums[i];
                }
            }
            return nums[0] == nums[1] ? -1 : nums[0];
        }
        if(nums.size() == k) {
            return *max_element(nums.begin(), nums.end());
        }

        if(nums.front() == nums.back()) return -1;

        for(int i = 1; i < nums.size() - 1; i++) {
            if(nums[i] == nums.front()) nums.front() = -1;
            else if(nums[i] == nums.back()) nums.back() = -1;
        }
        
        return max(nums.front(), nums.back());
    }
};