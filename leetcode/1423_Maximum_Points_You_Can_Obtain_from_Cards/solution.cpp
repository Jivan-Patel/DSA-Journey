class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector <int> track;
        int points = 0, n = cardPoints.size();

        for(int i = n-k; i <n; i++) {
            track.push_back(cardPoints[i]);
            points += cardPoints[i];
        }

        for(int i = 0; i < k; i++) track.push_back(cardPoints[i]);

        int maxPoint = points, low = 0, high = k;
        
        while(high < track.size()) {
            points += track[high++] - track[low++];
            maxPoint = max(maxPoint, points);
        }

        return maxPoint;
    }
};