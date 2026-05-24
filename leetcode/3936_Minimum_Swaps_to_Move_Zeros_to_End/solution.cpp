class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zeroes = 0, perfectZeroes = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) zeroes++;
        }

        for(int i = n - 1; i >= n - zeroes; i--) {
            if(nums[i] == 0) perfectZeroes++;
        }
        
        return zeroes - perfectZeroes;
    }
};