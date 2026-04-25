class Solution {
public:
    int subtractProductAndSum(int n) {
        int dprod = 1;
        int dsum = 0;
        while (n > 0) {
            int digit = n % 10;
            dprod *= digit;
            dsum += digit;
            n /= 10;
        }
        return dprod - dsum;
    }
};