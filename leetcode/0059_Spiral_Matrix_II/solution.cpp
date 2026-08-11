class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m = n * n, num = 1;
        int i = 0, j = 0;
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        while (num <= m) {
            // left -> right
            while (j < n && matrix[i][j] == 0) {
                matrix[i][j] = num++;
                j++;
            }
            j--;

            // top->bottom
            i++;
            while (i < n && matrix[i][j] == 0) {
                matrix[i][j] = num++;
                i++;
            }
            i--;

            // right->left
            j--;
            while (j >= 0 && matrix[i][j] == 0) {
                matrix[i][j] = num++;
                j--;
            }
            j++;

            // bottom->top
            i--;
            while (i >= 0 && matrix[i][j] == 0) {
                matrix[i][j] = num++;
                i--;
            }
            i++;

            j++;
        }

        return matrix;
    }
};