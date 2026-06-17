class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> track;

        for(char l : sentence) {
            track.insert(l);
        }

        return track.size() == 26;
    }
};