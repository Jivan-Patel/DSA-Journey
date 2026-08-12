class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10) return {};

        vector<string> res;
        unordered_map<string, int> seen;

        string subStr = s.substr(0, 10);
        cout << subStr << endl;

        seen[subStr]++;
        int high = 10;

        while(high < s.size()) {
            subStr.erase(0, 1);
            subStr.push_back(s[high]);

            if(seen[subStr] == 1) res.push_back(subStr);

            seen[subStr]++;
            high++;
        }
         
        return res;
    }
};