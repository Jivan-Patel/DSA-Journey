class Solution {
public:
    bool divideArray(vector<int>& nums) {
        if (nums.size() % 2 == 1) {
            return 0;
        }
        map<int, int> freq;
        for (int num : nums) {
            freq[num] ? freq[num]++ : freq[num] = 1;
        }
        for (auto& [num, frequency] : freq) {
            if (frequency % 2 == 1)
                return 0;
        }
        return 1;
    }
};