class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for (char ch : s) {
            int value = ch - 'a' + 1;
            while (value > 0) {
                sum += value % 10;
                value /= 10;
            }
        }
        for (int i = 1; i < k; i++) {
            int temp = 0;
            while (sum > 0) {
                temp += sum % 10;
                sum /= 10;
            }
            sum = temp;
        }
        return sum;
    }
};