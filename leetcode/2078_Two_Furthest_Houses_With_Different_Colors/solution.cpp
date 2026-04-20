class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDis = 0;
        for (int i = 0; i < n; i++) {
            int j = n - 1;
            while (j > i && j - i > maxDis && colors[i] == colors[j])
                j--;
            if (i != j) maxDis = max(maxDis, j - i);
        }
        return maxDis;
    }
};