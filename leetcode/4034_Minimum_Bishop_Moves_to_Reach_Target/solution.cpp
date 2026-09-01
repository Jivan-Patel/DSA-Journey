class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        // different color of box then not possible
        if((source[0] + source[1]) % 2 != (target[0] + target[1]) % 2) return -1;

        // diagnol check
        else if((source[0] + source[1]) == (target[0] + target[1]) || // dir -> '/'
            (source[0] - source[1]) == (target[0] - target[1])  // dir -> '\'
        ) return 1;

        // not in diagonal
        else return 2;
    }
};