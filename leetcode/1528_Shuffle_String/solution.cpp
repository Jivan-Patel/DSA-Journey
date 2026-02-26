class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int i = 0;
        vector<int> res(indices.size());
        for (int index : indices) {
            res[index] = s[i];
            i++;
        }
        string result = "";
        for (char ch : res) {
            result += ch;
        }
        return result;
    }
};