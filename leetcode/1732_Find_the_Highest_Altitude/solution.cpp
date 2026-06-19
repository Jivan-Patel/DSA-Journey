class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAlti = 0;
        int maxAlti = 0;
        for(int netGain : gain) {
            currentAlti += netGain;
            maxAlti = max(maxAlti, currentAlti);
        }
        return maxAlti;
    }
};