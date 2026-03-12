class Solution {
public:
    int mySqrt(int x) {
        int i = 0;
        long int j = x;
        while (i <= j) {
            long int mid = (i + j) / 2;
            if (mid * mid < x) {
                i = mid + 1;
                if (i * i > x)
                    return mid;
            } else if (mid * mid > x) {
                j = mid - 1;
                if (j * j < x)
                    return j;
            } else {
                return mid;
            }
        }
        return 0;
    }
};