class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector <int> result(n);

        int left = 0;
        int right = n - 1;

        int i = n - 1;

        while(left <= right) {
            int ls = nums[left] * nums[left];
            int rs = nums[right] * nums[right];

            if(ls > rs) {
                result[i] = ls;
                left++;
            }
            else {
                result[i] = rs;
                right--;
            }
            i--;
        }

        return result;
    }
};