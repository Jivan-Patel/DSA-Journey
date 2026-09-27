class Solution {
    void reversePart(string &s, int st, int end) {
        while(st < end) {
            swap(s[st++], s[end--]);
        }
    }

public:
    string reverseParentheses(string s) {
        stack<int> openIdx;
        string temp = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                openIdx.push(i);
            } 
            else if (s[i] == ')') {
                reversePart(s, openIdx.top() + 1, i - 1);
                openIdx.pop();
            }
        }

        for(char ch : s) {
            if(ch != '(' && ch != ')') temp += ch;
        }
        
        return temp;
    }
};