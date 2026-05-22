class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prod = 1;
        bool isZero = false;
        bool manyZero = false;

        for(int num: nums) {
            if(num == 0) {
                if(!isZero) isZero = true;
                else manyZero = true;
                continue;
            }
            prod *= num;
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0 && !manyZero) {
                ans.push_back(prod);
            }
            else if(nums[i] == 0 && manyZero) ans.push_back(0);
            else if(isZero) ans.push_back(0);
            else ans.push_back(prod / nums[i]);
        }
        return ans;
    }
};