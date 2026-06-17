class Solution {
public:
    string simplifyPath(string path) {
        vector<string> track;
        string current = "";

        for(int i = 0; i < path.size(); i++) {
            if(path[i] != '/') current += path[i];
            if(path[i] == '/' || i + 1 == path.size()) {
                if(current == "..") {
                    if(!track.empty()) track.pop_back();
                }
                else if(current != "" && current != ".") track.push_back(current);

                current = "";
            }
        }

        string ans = "";

        for(int i = 0; i < track.size(); i++) ans += "/" + track[i];

        if(ans == "") ans = "/";

        return ans;

    }
};