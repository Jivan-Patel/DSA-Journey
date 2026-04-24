class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            while(i < j && (s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z') && (s[i] < '0' || s[i] > '9')) i++;
            while(i < j && (s[j] < 'a' || s[j] > 'z') && (s[j] < 'A' || s[j] > 'Z') && (s[j] < '0' || s[j] > '9')) j--;
            if(i > j) break;
            if(tolower(s[i]) != tolower(s[j])) return false;    
            i++;
            j--;
        }
        return true;
    }
};