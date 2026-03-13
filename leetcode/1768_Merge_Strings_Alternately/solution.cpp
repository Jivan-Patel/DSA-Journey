class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        string res = "";
        int l1 = word1.size();
        int l2 = word2.size();
        while (i < l1 || i < l2) {
            if (i < l1)
                res += word1[i];
            if (i < l2)
                res += word2[i];
            i++;
        }
        return res;
    }
};
