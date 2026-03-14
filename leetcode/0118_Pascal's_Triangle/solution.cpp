class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {{1}};
        for (int i = 0; i < numRows - 1; i++) {
            vector<int> next = {1};
            for (int j = 0; j < (int)result[i].size() - 1; j++) {
                next.push_back(result[i][j] + result[i][j + 1]);
            }
            next.push_back(1);
            result.push_back(next);
        }
        return result;
    }
};