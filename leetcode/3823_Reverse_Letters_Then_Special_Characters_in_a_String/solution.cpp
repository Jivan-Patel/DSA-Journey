class Solution {
public:
    string reverseByType(string s) {
        string res;
        int chI = s.size() - 1, spI = s.size() - 1;

        for(char ch : s) {
            if(isalpha(ch)) {
                while(!isalpha(s[chI])) chI--;
                res += s[chI--];
            }
            else {
                while(isalpha(s[spI])) spI--;
                res += s[spI--];
            }
        }

        return res;
    }
};