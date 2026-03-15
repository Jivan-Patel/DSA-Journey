class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        multiset<int> sort;
        vector<int> index;
        int i = 0;
        for (int num : nums) {
            sort.insert(num);
        }
        for (int num : sort) {
            if (num == target)
                index.push_back(i);
            i++;
        }
        return index;
    }
};