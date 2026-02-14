class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey,
                     string ruleValue) {
        int cqIndex = (ruleKey == "type") ? 0 : (ruleKey == "color") ? 1 : 2;
        int count = 0;
        for (vector<string> item : items) {
            if (item[cqIndex] == ruleValue)
                count++;
        }
        return count;
    }
};