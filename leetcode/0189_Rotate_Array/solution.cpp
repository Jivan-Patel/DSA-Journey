class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int l = nums.size();
        vector<int> res;
        for(int i = l - k; i < l; i++) {
            res.push_back(nums[i]);
        }
        for(int i = 0; i < l - k; i++) {
            res.push_back(nums[i]);
        }
        nums = res;
    }
};