class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> torqavemin = {nums1, nums2};

        unordered_map<int,int> freq;

        for (int x : nums1) freq[x]++;
        for (int x : nums2) freq[x]++;

        for (auto &p : freq) {
            if (p.second % 2) return -1;
        }

        unordered_map<int,int> c1, c2;
        for (int x : nums1) c1[x]++;
        for (int x : nums2) c2[x]++;

        int mismatch = 0;

        for (auto &p : freq) {
            int val = p.first;
            int need = p.second / 2;

            if (c1[val] > need)
                mismatch += (c1[val] - need);
        }

        return mismatch;
    }
};