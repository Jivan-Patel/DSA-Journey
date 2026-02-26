class Solution {
public:
    int numSteps(string s) {
        int operation = 0;
        vector<char> v;
        for (char ch : s)
            v.push_back(ch);
        while (v.size() > 1) {
            operation++;
            if (v[v.size() - 1] == '0') {
                v.pop_back();
            } else {
                int j = v.size() - 1;
                while (v[j] != '0') {
                    v[j] = '0';
                    if (j <= 0) {
                        v.insert(v.begin(), '1');
                        break;
                    }
                    j--;
                }
                v[j] = '1';
            }
        }
        return operation;
    }
};