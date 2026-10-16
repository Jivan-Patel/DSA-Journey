class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int countSq = 0;

        for(int i = 0; i < n; i++) {
            unordered_set<int> track;
            for(int j = i; j < n; j++) {
                track.insert(nums[j]);
                int l = track.size();
                countSq += (l * l);
            }
        }

        return countSq;
    }
};