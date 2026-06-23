class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        set <int> track;
        for(int bulb : bulbs) {
            if(track.count(bulb)) track.erase(bulb);
            else track.insert(bulb);
        }
        vector<int> ans;
        for(int bulb: track) ans.push_back(bulb);

        return ans;
    }
};