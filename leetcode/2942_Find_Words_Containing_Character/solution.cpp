class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        for(int i = 0; i < words.size(); i++) {
            int idx = words[i].find(x);
            if(idx != -1) ans.push_back(i);
        }

        return ans;
    }
};