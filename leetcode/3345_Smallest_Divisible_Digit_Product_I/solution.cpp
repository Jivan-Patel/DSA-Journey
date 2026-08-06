class Solution {
public:
    int smallestNumber(int n, int t) {
        int prod = 1;
        do {
            int temp = n;
            prod = 1;
            while(temp  > 0) {
                prod *= (temp % 10);
                temp /= 10;
            }
            n++;
        } while(prod % t != 0);

        return n-1;
    }
};