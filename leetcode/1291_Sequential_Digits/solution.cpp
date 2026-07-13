class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        for (int i = 1; i <= 9; i++) {
            int n = 0;
            for (int j = i; j <= 9; j++) {
                n = n*10 + j;
                if(n >= low && n <= high) res.push_back(n);
            }
        }
        sort(res.begin(), res.end());

        return res;
    }
};