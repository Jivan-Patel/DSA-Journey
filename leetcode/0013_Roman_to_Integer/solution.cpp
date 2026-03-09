class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        int l = s.size();
        for (int i = 0; i < l; i++) {
            char letter = s[i];
            if (letter == 'V') {
                if (i > 0 && s[i - 1] == 'I') {
                    num += 3;
                } else {
                    num += 5;
                }
            } else if (letter == 'X') {
                if (i > 0 && s[i - 1] == 'I') {
                    num += 8;
                } else {
                    num += 10;
                }
            } else if (letter == 'L') {
                if (i > 0 && s[i - 1] == 'X') {
                    num += 30;
                } else {
                    num += 50;
                }
            } else if (letter == 'C') {
                if (i > 0 && s[i - 1] == 'X') {
                    num += 80;
                } else {
                    num += 100;
                }
            } else if (letter == 'D') {
                if (i > 0 && s[i - 1] == 'C') {
                    num += 300;
                } else {
                    num += 500;
                }
            } else if (letter == 'M') {
                if (i > 0 && s[i - 1] == 'C') {
                    num += 800;
                } else {
                    num += 1000;
                }
            } else if (letter == 'I') {
                num++;
            }
        }
        return num;
    }
};