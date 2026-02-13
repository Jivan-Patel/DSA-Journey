class Solution {
public:
    int countKeyChanges(string s) {
    int count = 0;
    int length = s.size();
    for (int i = 0; i < length - 1; i++) {
        if (tolower(s[i]) != tolower(s[i + 1])) count++;
    }
    return count;        
    }
};