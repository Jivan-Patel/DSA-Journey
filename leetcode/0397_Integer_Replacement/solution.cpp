class Solution {
public:
    int integerReplacement(int n) {
        int count = 0;
        while (n > 1) {
            if (n % 2 == 0)
                n /= 2;
            else if ((n - 1) % 4 == 0 || n == 3)
                n--;
            else if (n == 2147483647) {
                n--;
                count--;
            } else
                n++;
            count++;
        }
        return count;
    }
};