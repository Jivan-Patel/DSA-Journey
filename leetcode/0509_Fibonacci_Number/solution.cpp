class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        int f1 = 0;
        int f2 = 1;
        int current = 1;
        int i = 2;
        while (i < n) {
            f1 = f2;
            f2 = current;
            current = f1 + f2;
            i++;
        }
        return current;
    }
};