class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for (string token : tokens) {
            if(token == "+" || token == "-" ||token == "*" ||token == "/") {
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();

                if (token == "+") num.push(b + a);
                else if (token == "-") num.push(b - a);
                else if (token == "*") num.push(b * a);
                else if (token == "/") num.push(b / a);
               
            } 
            else {
                int n = stoi(token);
                num.push(n);
            }
        }
        return num.top();
    }
};