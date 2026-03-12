class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string r1 = "qwertyuiop";
        string r2 = "asdfghjkl";
        string r3 = "zxcvbnm";
        vector<string> res;
        for (string word : words) {
            char fch = tolower(word[0]);
            auto* ptr = &r1;
            bool isSameRow = true;
            if (r2.find(fch) != string::npos) {
                ptr = &r2;
            } else if (r3.find(fch) != string::npos) {
                ptr = &r3;
            }
            for (char ch : word) {
                if (ptr->find(tolower(ch)) == string::npos) {
                    isSameRow = false;
                    break;
                }
            }
            if (isSameRow)
                res.push_back(word);
        }
        return res;
    }
};