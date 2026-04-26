class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> validElements;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            bool greaterThanLeft = true;

            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) {
                    greaterThanLeft = false;
                    break;
                }
            }

            bool greaterThanRight = true;

            if (!greaterThanLeft) {
                for (int j = i + 1; j < n; j++) {
                    if (nums[i] <= nums[j]) {
                        greaterThanRight = false;
                        break;
                    }
                }
            }

            if (greaterThanLeft || greaterThanRight) {
                validElements.push_back(nums[i]);
            }
        }

        return validElements;
    }
};