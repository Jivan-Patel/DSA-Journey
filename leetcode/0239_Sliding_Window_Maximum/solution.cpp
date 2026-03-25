class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deque;
        for (int i = 0; i < k; i++) {
            while (deque.size() > 0 && nums[deque.back()] <= nums[i]) {
                deque.pop_back();
            }
            deque.push_back(i);
        }
        vector<int> res;
        for (int i = k; i < nums.size(); i++) {
            res.push_back(nums[deque.front()]);
            while (deque.size() > 0 && deque.front() <= i - k) {
                deque.pop_front();
            }
            while (deque.size() > 0 && nums[deque.back()] <= nums[i]) {
                deque.pop_back();
            }
            deque.push_back(i);
        }
        res.push_back(nums[deque.front()]);
        return res;
    }
};