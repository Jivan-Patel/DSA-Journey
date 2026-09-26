class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> track;
        string res = "";

        for(vector<string> pair: knowledge) {
            track[pair[0]] = pair[1];
        }
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                string temp = "";
                i++;
                while(s[i] != ')') {
                    temp += s[i++];
                }
                res += track[temp] != "" ? track[temp] : "?";
            }
            else {
                res += s[i];
            }
        }

        return res;

    }
};