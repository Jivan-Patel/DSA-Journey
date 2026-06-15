class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size(), "");
        map<int, int> order;

        for(int i = 0; i < score.size(); i++) {
            order[score[i]] = i;
        }

        int rank = order.size();
        
        for(auto [s, i] : order) {
            if(rank == 1) ans[i] = "Gold Medal";
            else if(rank == 2) ans[i] = "Silver Medal";
            else if(rank == 3) ans[i] = "Bronze Medal";
            else ans[i] = to_string(rank);

            rank--;
        }
        return ans;
    }
};