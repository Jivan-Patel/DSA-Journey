class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int maxI = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[maxI] < nums[i])
                maxI = i;
        }
        return maxI;
    }
};