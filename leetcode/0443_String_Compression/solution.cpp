class Solution {
public:
    int compress(vector<char>& chars) {
        int cur = 0, i = 0;

        while (i < chars.size()) {
            int j = i + 1;

            while (j < chars.size() && chars[j] == chars[i]) {
                j++;
            }

            chars[cur++] = chars[i];

            if (j - i > 1) {
                string s = to_string(j - i);
                for (char c : s) {
                    chars[cur++] = c;
                }
            }

            i = j;
        }

        return cur;
    }
};