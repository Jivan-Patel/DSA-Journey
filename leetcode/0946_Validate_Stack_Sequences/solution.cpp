class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        int n1 = pushed.size(), n2 = popped.size();
        stack <int> st;
        while(i < n1 && j < n2) {
            if(!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
            else {
                st.push(pushed[i]);
                i++;
            }
        }
        if(i < n1 && j == n2) return false;

        while(j < n2 && !st.empty()) {
            if(st.top() == popped[j]) {
                st.pop();
                j++;
            } 
            else return false;
        }

        return st.empty();
    }
};