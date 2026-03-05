class Solution {
public:
    int pivotInteger(int n) {
        int left = 1;
        int right = n * (n + 1) / 2;
        int i = 1;
        while (left < right) {
            right -= i;
            i++;
            left += i;
        }
        if (left == right)
            return i;
        return -1;
    }
};