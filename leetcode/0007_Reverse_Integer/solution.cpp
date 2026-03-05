class Solution {
public:
    int reverse(int x) {
        int temp;
        int sign;
        if (x >= 0) {
            temp = x;
            sign = 1;
        } else {
            if (x == -(pow(2, 31)))
                temp = 0;
            else
                temp = x * (-1);
            sign = -1;
        }

        long long int res = 0;
        while (temp != 0) {
            res = (res * 10) + (temp % 10);
            temp = temp / 10;
        }

        return (res * sign >= -(pow(2, 31)) && res * sign <= (pow(2, 31) - 1))
                   ? res * sign
                   : 0;
    }
};