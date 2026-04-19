class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxD = 0;
        int j = 0;
        for(int i = 0; i < nums1.size(); i++) {
            while(j < nums2.size() && (j <= i || nums1[i] <= nums2[j])) j++;
            if(nums1[i] <= nums2[j-1])
                maxD = max(maxD, j-i-1);
        }
        return maxD;
    }
};