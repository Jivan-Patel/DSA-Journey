class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int compatibleSum = 0;
        int st = max(n - k, 1);

        for(int x = st; x <= n + k; x++) {
            if((n & x) == 0) compatibleSum += x;
        }

        return compatibleSum;
    }
};