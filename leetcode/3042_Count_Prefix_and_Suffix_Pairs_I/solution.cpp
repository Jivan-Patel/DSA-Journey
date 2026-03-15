class Solution {
private:
    bool isPrefixAndSuffix(string str1, string str2) {
        int l1 = str1.size();
        int l2 = str2.size();
        if (l2 < l1)
            return false;
        if (str2.substr(0, l1) != str1 || str2.substr(l2 - l1) != str1)
            return false;
        return true;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int len = words.size();
        int count = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (isPrefixAndSuffix(words[i], words[j]))
                    count++;
            }
        }
        return count;
    }
};