class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int l = words.size();
        int pl = pref.size();
        for (int i = 0; i < l; i++) {
            bool check = true;
            int j = 0;
            while (j < pl) {
                if (words[i][j] != pref[j]) {
                    check = false;
                    break;
                }
                j++;
            }
            if (check)
                count++;
        }
        return count;
    }
};