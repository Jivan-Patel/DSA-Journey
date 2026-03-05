class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int sum = 0;
        set<int> uniqueNum;
        int repeatedNum = -1;
        int lenI = grid.size();
        int lenJ = grid[0].size();
        for (int i = 0; i < lenI; i++) {
            for (int j = 0; j < lenJ; j++) {
                if (uniqueNum.count(grid[i][j]) == 1) {
                    repeatedNum = grid[i][j];
                } else {
                    uniqueNum.insert(grid[i][j]);
                    sum += grid[i][j];
                }
            }
        }
        vector<int> res = {repeatedNum,
                           ((lenI * lenJ) * ((lenI * lenJ) + 1) / 2) - sum};
        return res;
    }
};