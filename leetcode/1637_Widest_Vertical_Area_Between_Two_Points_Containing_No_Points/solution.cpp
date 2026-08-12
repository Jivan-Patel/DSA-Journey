class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xCoords;
        for(int i = 0; i < points.size(); i++) {
            xCoords.push_back(points[i][0]);
        }
        
        sort(xCoords.begin(), xCoords.end());
        int maxDiff = 0;

        for(int i = 1; i < xCoords.size(); i++) {
            maxDiff = max(maxDiff, xCoords[i] - xCoords[i-1]);
        }

        return maxDiff;        
    }
};