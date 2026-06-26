class Solution {
public:
    bool isPathCrossing(string path) {
        int i = 0, j = 0;
        set<pair<int, int>> track = {{0, 0}};

        for(char c : path) {
            if(c == 'N') j++;
            else if(c == 'S') j--;
            else if(c == 'E') i++;
            else if(c == 'W') i--;

            if(track.find({i, j}) != track.end()) return true;
            track.insert({i, j});
        } 

        return false;
    }
};