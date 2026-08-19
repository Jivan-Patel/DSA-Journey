class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> track;

        for (int i = 0; i < reservedSeats.size(); i++) {
            track[reservedSeats[i][0] - 1].push_back(reservedSeats[i][1] - 1);
        }

        int groupCount = (n - track.size()) * 2;

        for (auto&[i, col] : track) {
            vector<bool> row(10, true);
            for(int seat : track[i]) {
                row[seat] = false;
            }
            if(row[1] && row[2] && row[3] && row[4]){
                row[4] = false;
                groupCount++;
            }
            if(row[3] && row[4] && row[5] && row[6]) {
                row[6] = false;
                groupCount++;
            }
            if(row[5] && row[6] && row[7] && row[8]) {
                groupCount++;
            }
        }

        return groupCount;
    }
};