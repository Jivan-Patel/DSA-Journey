class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res = {intervals[0]};

        for (int i = 1; i < intervals.size(); i++) {
            int range = res.back()[1];
            
            if (range < intervals[i][0]) {
                res.push_back({intervals[i][0], intervals[i][1]});
            } 
            else if (range < intervals[i][1]) {
                res.back()[1] = intervals[i][1];
            }
        }

        return res;
    }
};