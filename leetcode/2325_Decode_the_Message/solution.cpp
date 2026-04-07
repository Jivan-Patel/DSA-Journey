class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> decode;
        char alpha = 'a';
        string res;
        for(int ch: key) {
            if(!decode[ch] && ch != ' ') {
                decode[ch] = alpha;
                alpha++;
            }
        }
        decode[' '] = ' ';
        for(char ch: message) {
            res += decode[ch];
        }
        return res;
    }
};