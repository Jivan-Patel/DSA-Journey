class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map <string, pair<int, int>> track;
        for(int i = 0; i < list1.size(); i++) {
            track[list1[i]] = {i, -1};
        }
        for(int i = 0; i < list2.size(); i++) {
            if(track.count(list2[i]) > 0) {
                track[list2[i]].second = i;
            }
        }
        map <int, vector<string>> temp;
        for (auto &[s, p] : track) {
            auto &[i, j] = p;
            if(j != -1) {
                temp[i+j].push_back(s);
            }
        }

        return temp.begin()->second;
    }
};