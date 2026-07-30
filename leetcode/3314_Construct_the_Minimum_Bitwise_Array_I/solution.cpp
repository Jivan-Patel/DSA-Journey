class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int j = 0;
            while(j < nums[i] && ((j) | (j + 1)) != nums[i]) j++;

            if(j < nums[i]) ans.push_back(j);
            else ans.push_back(-1);
        }
        return ans;
    }
};