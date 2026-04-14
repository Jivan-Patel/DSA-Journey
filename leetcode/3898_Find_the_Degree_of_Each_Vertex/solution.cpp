class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> res;
        for(int i = 0; i < matrix.size(); i++) {
            res.push_back(0);
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 1) res[i]++;
            }
        }
        return res;
    }
};