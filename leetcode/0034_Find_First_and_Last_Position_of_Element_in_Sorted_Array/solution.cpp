class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        int resI = -1, resJ = -1;
        while (j >= i) {
            if (nums[i] == target)
                resI = i;
            else
                i++;
            if (nums[j] == target)
                resJ = j;
            else
                j--;
            if (resI != -1 && resJ != -1)
                break;
        }
        return { resI, resJ };
    }
};