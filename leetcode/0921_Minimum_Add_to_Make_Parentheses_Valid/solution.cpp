class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> open;
        int count = 0;
        for(char ch: s) {
            if(ch == '(') open.push(ch);
            else if(!open.empty()) open.pop();
            else count++;
        }
        return count + open.size();
    }
};