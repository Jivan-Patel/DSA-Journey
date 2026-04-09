class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size();
        string res;
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while (i < s.size()) {
            if (!vowel.count(s[i]))
                res += s[i];
            else {
                j--;
                while (j >= 0 && !vowel.count(s[j]))
                    j--;
                res += (j >= 0) ? s[j] : s[i];
            }
            i++;
        }
        return res;
    }
};