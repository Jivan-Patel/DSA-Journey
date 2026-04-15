class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int minDis = INT_MAX;
        int n = words.size();
        for(int i = 0; i < n; i++) {
            if(words[i] == target) {
                minDis = min(minDis, abs(startIndex - i));
                minDis = min(minDis, abs(i - startIndex - n));
                minDis = min(minDis, abs(startIndex - i - n));
            }
        }
        return minDis < INT_MAX ? minDis : -1; 
    }
};
