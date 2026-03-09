class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int smallCount = 0;
        for (int num : nums) {
            if (num < k)
                smallCount++;
        }
        return smallCount;
    }
};