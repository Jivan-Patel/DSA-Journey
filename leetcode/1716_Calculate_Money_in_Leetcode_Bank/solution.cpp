class Solution {
public:
    int totalMoney(int n) {
        int week = 0;
        int result = 0;
        while (n > 0) {
            int check = (n > 7) ? 7 : n;
            result += ((check + week) * (check + 1 + week) / 2) -
                      (week * (week + 1) / 2);
            n = n - check;
            week++;
        }
        return result;
    }
};