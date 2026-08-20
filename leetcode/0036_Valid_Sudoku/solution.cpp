class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            vector<bool> track(9, false);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (track[board[i][j] - '0']) {
                        return false;
                    }
                    track[board[i][j] - '0'] = true;
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            vector<bool> track(9, false);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (track[board[j][i] - '0']) {
                        return false;
                    }
                    track[board[j][i] - '0'] = true;
                }
            }
        }

        for (int k = 0; k < 9; k += 3) {
            for (int l = 0; l < 9; l += 3) {
                vector<bool> track(9, false);
                for (int i = k; i < k + 3; i++) {
                    for (int j = l; j < l + 3; j++) {
                        if (board[i][j] != '.') {
                            if (track[board[i][j] - '0']) {
                                return false;
                            }
                            track[board[i][j] - '0'] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};