class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        for(int i = heights.size() -1; i >= 0; i--) {
            int seen = 0;
            while(!st.empty() && st.top() < heights[i]) {
                st.pop();
                seen++;
            }
            if(!st.empty()) seen++;
            
            st.push(heights[i]);
            heights[i] = seen;
        }

        return heights;
    }
};