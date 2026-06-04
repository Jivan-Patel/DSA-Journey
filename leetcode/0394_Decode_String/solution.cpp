class Solution {
private:
    string ans(string &s, int &i) {
        string str = "";
        while(i < s.size() && s[i] != ']') {
            if(isalpha(s[i])) {
                str += s[i];
                i++;
            } 
            else if(isdigit(s[i])) {
                int num = 0;

                while(isdigit(s[i])) {
                    num = (num * 10) + (s[i] - '0');
                    i++;
                }

                i++; // skip '['

                string temp = ans(s, i);

                i++; // skip ']'
                
                while(num > 0) {
                    str += temp;
                    num--;
                }
            }
        }
        return str;
    }

public:
    string decodeString(string s) {
        int i = 0;

        return ans(s, i);
    }
};