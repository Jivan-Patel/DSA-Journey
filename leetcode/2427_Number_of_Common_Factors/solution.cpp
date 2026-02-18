class Solution {
public:
    int commonFactors(int a, int b) {
        int count = 0;
        int min = a < b ? a : b;
        for (int i = min; i > 0; i--) {
            if (a % i == 0 && b % i == 0)
                count++;
        }
        return count;
    }
};