class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int leftSum = 0, rightSum = 0;
        vector<int> res;

        for(int n: nums) rightSum += n;

        for(int num: nums) {
            rightSum -= num;
            int ans = abs(leftSum - rightSum);
            res.push_back(ans);
            leftSum += num;
        }

        return res;
    }
};