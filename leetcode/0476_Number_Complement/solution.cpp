class Solution {
public:
    int findComplement(int num) {
        string binary = "";
        int result = 0;
        while (num > 0) {
            binary += num % 2 ? '0' : '1';
            num /= 2;
        }
        long int power = 1;
        for (char ch : binary) {
            if (ch == '1') {
                result += power;
            }
            power *= 2;
        }
        return result;
    }
};