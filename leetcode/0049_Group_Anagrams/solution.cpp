class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<map<char, int>, vector<int>> anagram;
        for (int i = 0; i < strs.size(); i++) {
            map<char, int> letterCount;
            for(char ch: strs[i]) {
                letterCount[ch]++;
            }
            anagram[letterCount].push_back(i);
        }
        for (auto& [key, idx] : anagram) {
            int lastI = res.size();
            res.push_back({});
            for(int i : idx) {
                res[lastI].push_back(strs[i]);
            }
        }
        return res;
    }
};