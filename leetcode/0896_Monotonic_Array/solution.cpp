class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool monotonicInc = true, monotonicDec = true;

        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i+1]) {
                monotonicInc = false;
            }
            else if(nums[i] < nums[i+1]) {
                monotonicDec = false;
            }
            if(!monotonicInc && !monotonicDec) return monotonicInc;
        }

        return monotonicInc || monotonicDec;
    }
};