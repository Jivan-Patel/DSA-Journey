class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        if(nums.empty()) return {};

        vector<int> res = {nums[0]};
        int currentCount = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(res.back() == nums[i]) {
                currentCount++;
                if(currentCount <= k) {
                    res.push_back(nums[i]);
                }
            }
            else {
                res.push_back(nums[i]);
                currentCount = 1;
            }
        }        
        return res;
    }
};