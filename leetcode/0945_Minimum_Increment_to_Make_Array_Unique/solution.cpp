class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int inc = 0;

        for(int i = 1; i < nums.size(); i++) {
            while(nums[i-1] >= nums[i]){
                nums[i]++;
                inc++;
            }
        }

        return inc;
    }
};