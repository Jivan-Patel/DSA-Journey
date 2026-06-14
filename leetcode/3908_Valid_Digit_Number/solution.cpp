class Solution {
public:
    bool validDigit(int n, int x) {
        bool isValid = false;
        int digit = 0;

        while(n > 0) {
            digit = n % 10;
            if(digit == x) isValid = true;

            n /= 10;
        }
        if(digit == x) isValid = false;

        return isValid;
    }
};