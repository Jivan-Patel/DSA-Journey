class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int flag = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            flag++;
        }
        return left << flag;
    }
};