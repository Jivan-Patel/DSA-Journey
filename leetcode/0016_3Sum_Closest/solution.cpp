class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = 0, minDiff = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                for(int k = j+1; k < nums.size(); k++) {
                    int diff = abs(nums[i] + nums[j] + nums[k] - target);
                    if(diff < minDiff){
                        sum = nums[i] + nums[j] + nums[k];
                        minDiff = diff;
                    }
                }
            }
        }
        return sum;
    }
};