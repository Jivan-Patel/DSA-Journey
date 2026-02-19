class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pairs = 0;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (nums[i] == nums[j])
                    pairs++;
            }
        }
        return pairs;
    }
};