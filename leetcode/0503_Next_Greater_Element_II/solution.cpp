class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int len = nums.size();
        vector<int> ans(len, 0);

        for (int i = 2 * len - 1; i >= 0; i--) {
            while (st.size() > 0 && nums[st.top()] <= nums[i % len]) {
                st.pop();
            }
            ans[i % len] = st.empty() ? -1 : nums[st.top()];
            st.push(i % len);
        }

        return ans;
    }
};