class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0;
        for(int n : nums) {
            if(n == 0) zero++;
            else if(n == 1) one++;
        }
        int curI = 0;
        for(int i = 0; i < zero; i++) nums[curI++] = 0;
        for(int i = 0; i < one; i++) nums[curI++] = 1;
        for(int i = curI; i < nums.size(); i++) nums[i] = 2;
    }
};