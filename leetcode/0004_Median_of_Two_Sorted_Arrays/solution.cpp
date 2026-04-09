class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0, i2 = 0;
        int current = 0, prev = 0;
        int len = nums1.size() + nums2.size();

        for (int k = 0; k <= len / 2; k++) {
            prev = current;
            if(i1 < nums1.size() && (i2 >= nums2.size() || nums1[i1] < nums2[i2])) {
                current = nums1[i1];
                i1++;
            }
            else {
                current = nums2[i2];
                i2++;
            }
        }
        if (len % 2 == 0) return (double) (current + prev) / 2;
        return current;
    }
};