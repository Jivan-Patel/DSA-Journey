class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> unique;
        for (int i = 0; i < nums.size(); i++) {
            unique.insert(nums[i]);
            if (unique.size() < i+1)
                return nums[i];
        }
        return 0;
    }
};