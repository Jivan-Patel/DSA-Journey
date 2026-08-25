class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> track;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                track[i + j].push_back(mat[i][j]);
            }
        }
        vector<int> res;

        for (int i = 0; i < m + n - 1; i++) {
            if (i % 2 == 0) {
                res.insert(res.end(), track[i].rbegin(), track[i].rend());
            }
            else {
                res.insert(res.end(), track[i].begin(), track[i].end());
            }
        }

        return res;
    }
};