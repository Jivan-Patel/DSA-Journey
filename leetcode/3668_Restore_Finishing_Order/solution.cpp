class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> res;
        for (int n : order) {
            if (binary_search(friends.begin(), friends.end(), n)) {
                res.push_back(n);
            }
        }
        return res;
    }
};