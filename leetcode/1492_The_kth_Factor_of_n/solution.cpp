class Solution {
public:
    int kthFactor(int n, int k) {
        int flag = 1;
        if (flag == k)
            return 1;
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                flag++;
                if (flag == k)
                    return i;
            }
        }
        if (n != 1)
            flag++;
        if (flag == k)
            return n;
        return -1;
    }
};