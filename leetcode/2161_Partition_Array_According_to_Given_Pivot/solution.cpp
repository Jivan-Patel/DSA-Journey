class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;
        int countP = 0;
        for (int num : nums) {
            if (num < pivot)
                result.push_back(num);
            else if (num == pivot)
                countP++;
        }
        for (int i = 1; i <= countP; i++)
            result.push_back(pivot);
        for (int num : nums)
            if (num > pivot)
                result.push_back(num);
        return result;
    }
};