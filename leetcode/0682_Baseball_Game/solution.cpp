class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> nums;
        int ans = 0;

        for(string operation: operations) {
            if(operation == "+") {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.push(a);
                nums.push(a+b);
            }
            else if(operation == "D") {
                int a = nums.top();
                nums.push(a*2);
            }
            else if(operation == "C") {
                nums.pop();
            }
            else {
                nums.push(stoi(operation));
            }
        }
        while(!nums.empty()) {
            ans += nums.top();
            nums.pop();
        }
        return ans;
    }
};