class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int bCount = 0, aCount = 0, nCount = 0;
        int lCount = 0, oCount = 0;

        for (char ch : text) {
            if (ch == 'b') bCount++;
            if (ch == 'a') aCount++;
            if (ch == 'n') nCount++;
            if (ch == 'l') lCount++;
            if (ch == 'o') oCount++;
        }
        int maxBallon = min({bCount, aCount, nCount, lCount / 2, oCount / 2});

        return maxBallon;
    }
};