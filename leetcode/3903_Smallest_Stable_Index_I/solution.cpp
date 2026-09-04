class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxNum = nums[0];

        int minNum = INT_MAX;
        vector<int> minArr(n, -1);

        for(int i = n - 1; i >=0; i--) {
            minNum = min(minNum, nums[i]);
            minArr[i] = minNum;
        }

        for(int i = 0; i < n; i++) {
            maxNum = max(maxNum, nums[i]);
            if(maxNum - minArr[i] <= k) return i;
        }
        return -1;
    }
};