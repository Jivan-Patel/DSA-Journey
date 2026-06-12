class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int max1 = INT_MIN, max2 = INT_MIN;

        for(int n : nums1) max1 =max(max1, n);
        for(int n : nums2) max2 = max(max2, n);

        return max2 - max1;
    }
};