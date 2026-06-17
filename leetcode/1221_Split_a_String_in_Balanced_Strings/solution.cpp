class Solution {
public:
    int balancedStringSplit(string s) {
        int lCount = 0, rCount = 0;
        int balanceStr = 0;

        for(char ch : s) {
            if(ch == 'R') rCount++;
            else lCount++;

            if(lCount == rCount) balanceStr++;
        }

        return balanceStr;
    }
};