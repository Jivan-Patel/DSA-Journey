class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        while(i < n && s[i] == ' ') i++;

        if(i == n) return 0;

        long ans = 0;
        bool isPositive = true;

        if(s[i] == '+' || s[i] == '-') {
            isPositive = s[i] == '+';
            i++;
        }

        while(s[i] >= '0' && s[i] <= '9') {
            if(isPositive && ans * 10 + s[i] - '0' >= INT_MAX) {
                return INT_MAX;
            }
            else if(!isPositive && -1 * (ans * 10 + s[i] - '0') <= INT_MIN) {
                return INT_MIN;
            }
            
            ans *= 10;
            ans += s[i] - '0';
            i++;
        }

        if(!isPositive) ans *= -1;

        return ans;
    }
};