class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string word : words) {
            int i = 0, j = word.size() - 1;
            bool flag = true;
            while (i < j) {
                if (word[i] != word[j]) {
                    flag = false;
                    break;
                }
                i++;
                j--;
            }
            if (flag)
                return word;
        }
        return "";
    }
};