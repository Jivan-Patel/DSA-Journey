class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int i = 0;
        int j = height.size() - 1;
        while (j > i) {
            int h = min(height[i], height[j]);
            int w = j - i;
            maxA = max(maxA, h * w);

            if(height[i] < height[j]) i++;
            else j--;
        }
        return maxA;
    }
};