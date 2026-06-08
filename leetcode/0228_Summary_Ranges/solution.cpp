class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> ans;

        int i = 0;

        while (i < nums.size()) {
            int st = nums[i];

            while (i < nums.size() - 1 && nums[i+1] == nums[i] + 1) i++;

            int end = nums[i];

            string range = to_string(st);
            if (st != end) range += "->" + to_string(end);

            ans.push_back(range);
            i++;
        }

        return ans;
    }
};