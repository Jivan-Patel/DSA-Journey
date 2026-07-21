class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size() < k) return 0;

        int sum = 0, low = 0, high = k;
        for(int i = 0; i < k; i++) sum += nums[i];
        
        int maxSum = sum;

        while(high < nums.size()) {
            sum += nums[high] - nums[low];
            maxSum = max(maxSum, sum);
            high++; 
            low++;
        }
        double maxAvg = (double) maxSum / k;
        return maxAvg;
    }
};