class Solution {
public:
    bool isValid(string s) {
        stack<char> track;

        for(char ch : s) {
            if(ch == '(' || ch == '[' || ch == '{') track.push(ch);
            else if(track.empty()) return false;
            else if(ch == ')') {
                if(track.top() != '(') return false;
                track.pop();
            }
            else if(ch == ']') {
                if(track.top() != '[') return false;
                track.pop();
            }
            else if(ch == '}') {
                if(track.top() != '{') return false;
                track.pop();
            }
        }
        return track.size() == 0;
    }
};