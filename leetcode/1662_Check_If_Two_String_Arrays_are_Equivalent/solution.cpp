class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "";
        string s2 = "";
        int l1 = word1.size();
        int l2 = word2.size();
        for (int i = 0; i < l1; i++)
            s1 += word1[i];
        for (int i = 0; i < l2; i++)
            s2 += word2[i];
        return s1 == s2;
    }
};