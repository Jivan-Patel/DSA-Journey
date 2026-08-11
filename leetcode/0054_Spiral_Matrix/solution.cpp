class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int i = 0, j = 0;

        while (res.size() < m * n) {
            // left -> right
            while (j < n && matrix[i][j] != 101) {
                res.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                j++;
            }
            j--;

            // top->bottom
            i++;
            while (i < m && matrix[i][j] != 101) {
                res.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                i++;
            }
            i--;

            // right->left
            j--;
            while (j >= 0 && matrix[i][j] != 101) {
                res.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                j--;
            }
            j++;

            // bottom->top
            i--;
            while (i >= 0 && matrix[i][j] != 101) {
                res.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                i--;
            }
            i++;

            j++;
        }

        return res;
    }
};