class Solution {
public:
    int countCommas(int n) {
        int count = 0;
        for(int i = 1000; i <= n; i++) {
            int digit = 0;
            int temp = i;
            while(temp > 0) {
                digit++;
                temp /= 10;
            }
            count += ((digit - 1) / 3);
        }
        return count;
    }
};