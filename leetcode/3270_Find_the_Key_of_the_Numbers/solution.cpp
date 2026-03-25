class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string res = "";
        while (num1 > 0 && num2 > 0 && num3 > 0) {
            int digit = min({num1 % 10, num2 % 10, num3 % 10});
            char d = digit + '0';
            res += d;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }
        reverse(res.begin(), res.end());
        return stoi(res);
    }
};