class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> check1;
        unordered_set<char> check2;
        int minI = s.size();
        for (int i = 0; i < s.size(); i++) {
            if ((check1[s[i]] && check1[s[i]] != t[i]) || (!check1[s[i]] && check2.count(t[i]))) {
                return false;
            }
            else {
                check1[s[i]] = t[i];
                check2.insert(t[i]);
            }
        }
        return true;
    }
};