class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            int smallCount = 0;
            for(int j = 0; j < nums.size(); j++) {
                if(nums[i] > nums[j]) smallCount++;
            }
            res.push_back(smallCount);
        }
        return res;
    }
};