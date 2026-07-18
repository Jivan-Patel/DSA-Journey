class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min = nums[0]; 
        int max = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (min > nums[i])
                min = nums[i];
            if (max < nums[i])
                max = nums[i];
        }
        int i = min;
        while (i > 0) {
            if (min % i == 0 && max % i == 0)
                return i;
            i--;
        }
        return 1;
    }
};