class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minI = 0, maxI = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minI]) minI = i;
            if (nums[i] > nums[maxI]) maxI = i;
        }
        cout << minI << " " << maxI;

        int minDis = min({
            max(minI + 1, maxI + 1), // both from front
            max(n - minI, n - maxI), // both from end
            n - minI + maxI + 1,     // minI from start and other from end
            minI + n - maxI + 1,     // minI from end and other from end
        });

        return minDis;
    }
};