class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res = {first};
        for (int num : encoded) {
            int ans = res.back() ^ num;
            res.push_back(ans);
        }
        return res;
    }
};