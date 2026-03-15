class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        long long i = 1000;
        long long comma = 1;
        while (i <= n) {
            long long end = min(n ,i * 1000 - 1);
            count += ((end - i + 1) * comma);
            comma++;
            i *= 1000;
        }
        return count;
    }
};