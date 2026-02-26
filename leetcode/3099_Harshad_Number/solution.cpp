class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int temp = x;
        int digitSum = 0;
        while (temp > 0) {
            digitSum += temp % 10;
            temp = temp / 10;
        }
        return (x % digitSum == 0) ? digitSum : -1;
    }
};