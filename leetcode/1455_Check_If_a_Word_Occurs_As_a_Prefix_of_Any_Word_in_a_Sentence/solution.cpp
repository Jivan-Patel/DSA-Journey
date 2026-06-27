class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i = 0;
        int word = 1;
        int n = sentence.size(), m = searchWord.size();

        while(i < n) {
            int j = 0;
            while(i + j < n && j < m && sentence[i+j] == searchWord[j]) j++;

            if(j == m) return word;

            while(i < n && sentence[i] != ' ') i++;
            i++;
            word++;
        }
        return -1;
    }
};