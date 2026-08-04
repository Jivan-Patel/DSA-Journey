class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int i = 1;
        for(int n = nums.front() + 1; n < nums.back(); n++) {
            if(nums[i] != n) {
                res.push_back(n);
            }
            else i++;
        }
        
        return res;
    }
};