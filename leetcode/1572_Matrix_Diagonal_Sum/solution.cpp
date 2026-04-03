class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                if(i == j || i+j+1 == mat[i].size()) {
                    sum += mat[i][j];
                }
            }
        }
        return sum;
    }
};