class Solution {
public:
    string removeOccurrences(string s, string part) {
        bool isRemove = true;
        int len = part.size();

        string ans = s;
        
        while (isRemove) {
            isRemove = false;
            auto pos = ans.find(part);

            if (pos != string::npos) {
                ans.erase(pos, len);
                isRemove = true;
            }
        }

        return ans;
    }
};