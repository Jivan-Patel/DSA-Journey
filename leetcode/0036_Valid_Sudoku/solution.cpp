class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> row;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (row.count(board[i][j])) {
                    return false;
                }
                row.insert(board[i][j]);
            }
        }
        for (int i = 0; i < 9; i++) {
            unordered_set<char> col;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (col.count(board[j][i])) {
                    return false;
                }
                col.insert(board[j][i]);
            }
        }
        int k = 0;
        while (k < 9) {
            int l = 0;
            while (l < 9) {
                unordered_set<char> box;
                for (int i = k; i < 3 + k; i++) {
                    for (int j = l; j < 3 + l; j++) {
                        if (board[i][j] == '.') {
                            continue;
                        }
                        if (box.count(board[i][j])) {
                            return false;
                        }
                        box.insert(board[i][j]);
                    }
                }
                l += 3;
            }
            k += 3;
        }
        return true;
    }
};