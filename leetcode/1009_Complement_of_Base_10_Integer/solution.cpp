class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;
        string binary = "";
        int num = 0;
        while (n > 0) {
            binary += n % 2 ? '1' : '0';
            n /= 2;
        }
        int power = 1;
        for (char ch : binary) {
            if (ch == '0') {
                num += power;
            }
            power *= 2;
        }
        return num;
    }
};