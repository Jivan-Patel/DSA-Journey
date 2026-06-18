class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> track(100, 0);

        for(int num : nums) {
            track[num - 1]++;
            if(track[num - 1] > 2) return false;
        }

        return true;
    }
};