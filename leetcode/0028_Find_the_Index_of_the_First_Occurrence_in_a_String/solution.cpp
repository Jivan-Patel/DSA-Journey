class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = 0;
        int i = 0;
        while(i < haystack.size()) {
            if(haystack[i] == needle[j]) {
                j++;
                i++;
            }
            else {
                i = i - j + 1;
                j = 0;
            }
            if(j == needle.size()) return i - j;
        }
        return -1;
    }
};