class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currentIdx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[currentIdx] != nums[i]) {
                currentIdx++;
                nums[currentIdx] = nums[i];
            }
        }
        return currentIdx + 1;
    }
};