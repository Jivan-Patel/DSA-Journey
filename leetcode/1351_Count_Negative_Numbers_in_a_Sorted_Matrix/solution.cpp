class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (auto& arr : grid) {
            int i = arr.size() - 1;
            while (i >= 0 && arr[i] < 0) {
                count++;
                i--;
            }
        }
        return count;
    }
};