class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddMin = INT_MAX, evenMin = INT_MAX;

        for (int n : nums1) {
            if (n % 2 == 0 && evenMin > n) evenMin = n;
            else if (n % 2 == 1 && oddMin > n) oddMin = n;
        }

        return oddMin == INT_MAX || oddMin < evenMin;
    }
};