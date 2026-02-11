class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int goodPair = 0;
        int l1 = nums1.size();
        int l2 = nums2.size();
        for (int i = 0; i < l1; i++) {
            if (nums1[i] % k != 0)
                continue;
            for (int j = 0; j < l2; j++) {
                if (nums1[i] % (nums2[j] * k) == 0)
                    goodPair++;
            }
        }
        return goodPair;
    }
};