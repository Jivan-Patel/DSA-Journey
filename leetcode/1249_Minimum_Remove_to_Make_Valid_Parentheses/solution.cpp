class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack <int> openBracket; 
        stack <int> closeBracket; 
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') openBracket.push(i);
            else if(s[i] == ')') {
                if(!openBracket.empty()) openBracket.pop();
                else closeBracket.push(i);
            }
        }
        string ans = s;
        while(!openBracket.empty() && !closeBracket.empty()) {
            if(openBracket.top() > closeBracket.top()) {
                ans.erase(openBracket.top() , 1);
                openBracket.pop();
            }
            else {
                ans.erase(openBracket.top() , 1);
                openBracket.pop();
            }
        }

        while(!openBracket.empty()) {
            ans.erase(openBracket.top() , 1);
            openBracket.pop();
        }
        while(!closeBracket.empty()) {
            ans.erase(closeBracket.top() , 1);
            closeBracket.pop();
        }

        return ans;
    }
};