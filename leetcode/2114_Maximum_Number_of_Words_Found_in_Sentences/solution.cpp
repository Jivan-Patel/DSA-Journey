class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;
        for(string sentence : sentences) {
            int word = 1;
            for(char ch : sentence) {
                if(ch == ' ') word++;
            }
            maxWords = max(word, maxWords);
        }

        return maxWords;
    }
};