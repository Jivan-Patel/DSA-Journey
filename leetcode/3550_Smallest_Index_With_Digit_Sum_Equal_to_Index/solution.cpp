class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            int test = nums[i];
            while (test > 0) {
                sum += (test % 10);
                test = test / 10;
            }
            if (sum == i) return i;
        }
        return -1;
    }
};