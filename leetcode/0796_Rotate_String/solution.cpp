class Solution {
public:
    bool rotateString(string s, string goal) {
        int i = 0;
        int j = 0;
        int n = goal.size();
        if(n != s.size()) return false;
        while(j < n) {
            while(j < n && s[i] != goal[j]) j++;
            string part = goal.substr(j, n-j);
            part += goal.substr(0, j);
            if(part == s) return true;
            j++;
        }
        return false;
    }
};