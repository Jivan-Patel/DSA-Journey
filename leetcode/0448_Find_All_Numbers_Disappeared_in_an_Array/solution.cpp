class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        vector<int> track(n, 0);

        for(int num : nums) track[num - 1]++;

        for(int i = 0; i < track.size(); i++) {
            if(track[i] == 0) ans.push_back(i+1);
        }

        return ans;
    }
};