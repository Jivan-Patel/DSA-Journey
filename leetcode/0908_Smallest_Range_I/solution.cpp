class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minNum = INT_MAX, maxNum = INT_MIN;
        
        for(int n : nums) {
            minNum = min(minNum, n);
            maxNum = max(maxNum, n);
        }
        // int diff = (maxNum - k) - (minNum + k);
        int diff = (maxNum - minNum - 2 * k);
        return max(0, diff);
    }
};