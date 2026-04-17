class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> revI;
        int minDiff = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int rev = 0;
            if (revI.count(nums[i])) {
                for (int idx : revI[nums[i]]) {
                    minDiff = min(minDiff, abs(i - idx));
                }
            }
            if (minDiff == 1)
                return minDiff;
            int num = nums[i];
            while (num > 0) {
                rev = rev * 10 + num % 10;
                num /= 10;
            }
            revI[rev].push_back(i);
        }
        return minDiff < INT_MAX ? minDiff : -1;
    }
};