class Solution {
public:
    int maxDepth(string s) {
        int openingBracket = 0;
        int ans = 0;

        for (char ch : s) {
            if (ch == '(') {
                openingBracket++;
                ans = max(ans, openingBracket);
            } 
            else if (ch == ')') openingBracket--;
        }

        return ans;
    }
};