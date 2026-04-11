class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res;
        for (int i = 0; i < n; i++) {
            int j = n - 1;
            bool isPalindrom = false;
            while (j > i && !isPalindrom) {
                while (j > i && s[j] != s[i]) j--;
                int l = i, r = j;
                while (l < r && s[l] == s[r]) {
                    l++;
                    r--;
                }
                isPalindrom = s[l] == s[r];
                j--;
            }
            if (isPalindrom && j - i + 1 >= res.size()) {
                res = "";
                for (int k = i; k <= j + 1; k++) res += s[k];
            }
        }
        if(!res[0]) res += s[0];
        return res;
    }
};