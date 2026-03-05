class Solution {
public:
    int reverseBits(int n) {
        string binary = "";
        while (n > 0) {
            binary += (n % 2) ? '1' : '0';
            n /= 2;
        }
        while (binary.size() < 32) {
            binary += '0';
        }
        int len = binary.size() - 1;
        int num = 0;
        long int power = 1;
        for (int i = len; i >= 0; i--) {
            if (binary[i] == '1') {
                num += power;
            }
            power *= 2;
        }
        return num;
    }
};