class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        string res = words[0];
        vector<string> ans;
        for (char ch : res) {
            int index = NULL;
            for (int j = 1; j < words.size(); j++) {
                index = words[j].find(ch);
                if (index == -1) break;
                words[j].erase(index, 1);
            }
            if(index != -1) ans.push_back(string(1, ch));
        }

        return ans;
    }
};