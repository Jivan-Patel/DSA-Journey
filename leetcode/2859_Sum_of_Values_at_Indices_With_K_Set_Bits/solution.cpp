class Solution {
public:
    bool checkIndex(int i, int k) {
        int sum = 0;
        while (i > 0) {
            sum += i % 2;
            if (sum > k)
                return false;
            i /= 2;
        }
        return sum == k;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (checkIndex(i, k)) {
                sum += nums[i];
            }
        }
        return sum;
    }
};